#include <stdio.h>

#define UInt32  unsigned int
#define Int32   int
#define UInt16  unsigned short
#define Char    char
#define UChar   unsigned char
#define Bool   unsigned char
#define True   1
#define False  0
#define IntNative int

void    panic( Char* );
void simpleSort ( Int32 lo, Int32 hi, Int32 d );
void qSort3 ( Int32 loSt, Int32 hiSt, Int32 dSt );

Int32   verbosity;

UChar    *block;    /*-- compress   --*/
UInt16   *quadrant; /*-- compress   --*/
Int32    *zptr;     /*-- compress   --*/ 
Int32    *ftab;     /*-- compress   --*/
Int32  last;

Int32  workDone;
Int32  workLimit;
Bool   firstAttempt;

#define NUM_OVERSHOOT_BYTES 20

/*---------------------------------------------*/

#define BIGFREQ(b) (ftab[((b)+1) << 8] - ftab[(b) << 8])

#define SETMASK (1 << 21)
#define CLEARMASK (~(SETMASK))

// 3 local arrays
void sortIt ( void )
{
   Int32 i, j, ss, sb;
   Int32 runningOrder[256];
   Int32 copy[256];
   Bool bigDone[256];
   UChar c1, c2;
   Int32 numQSorted;

   /*--
      In the various block-sized structures, live data runs
      from 0 to last+NUM_OVERSHOOT_BYTES inclusive.  First,
      set up the overshoot area for block.
   --*/

   if (verbosity >= 4) fprintf ( stderr, "        sort initialise ...\n" );
   for (i = 0; i < NUM_OVERSHOOT_BYTES; i++)
       block[last+i+1] = block[i % (last+1)];
   for (i = 0; i <= last+NUM_OVERSHOOT_BYTES; i++)
       quadrant[i] = 0;

   block[-1] = block[last];

   if (last < 4000) {

      /*--
         Use simpleSort(), since the full sorting mechanism
         has quite a large constant overhead.
      --*/
      if (verbosity >= 4) fprintf ( stderr, "        simpleSort ...\n" );
      for (i = 0; i <= last; i++) zptr[i] = i;
      firstAttempt = False;
      workDone = workLimit = 0;
      simpleSort ( 0, last, 0 );
      if (verbosity >= 4) fprintf ( stderr, "        simpleSort done.\n" );

   } else {

      numQSorted = 0;
      for (i = 0; i <= 255; i++) bigDone[i] = False;

      if (verbosity >= 4) fprintf ( stderr, "        bucket sorting ...\n" );

      for (i = 0; i <= 65536; i++) ftab[i] = 0;

      c1 = block[-1];
      for (i = 0; i <= last; i++) {
         c2 = block[i];
         ftab[(c1 << 8) + c2]++;
         c1 = c2;
      }

      for (i = 1; i <= 65536; i++) ftab[i] += ftab[i-1];

      c1 = block[0];
      for (i = 0; i < last; i++) {
         c2 = block[i+1];
         j = (c1 << 8) + c2;
         c1 = c2;
         ftab[j]--;
         zptr[ftab[j]] = i;
      }
      j = (block[last] << 8) + block[0];
      ftab[j]--;
      zptr[ftab[j]] = last;

      /*--
         Now ftab contains the first loc of every small bucket.
         Calculate the running order, from smallest to largest
         big bucket.
      --*/

      for (i = 0; i <= 255; i++) runningOrder[i] = i;

      {
         Int32 vv;
         Int32 h = 1;
         do h = 3 * h + 1; while (h <= 256);
         do {
            h = h / 3;
            for (i = h; i <= 255; i++) {
               vv = runningOrder[i];
               j = i;
               while ( BIGFREQ(runningOrder[j-h]) > BIGFREQ(vv) ) {
                  runningOrder[j] = runningOrder[j-h];
                  j = j - h;
                  if (j <= (h - 1)) goto zero;
               }
               zero:
               runningOrder[j] = vv;
            }
         } while (h != 1);
      }

      /*--
         The main sorting loop.
      --*/

      for (i = 0; i <= 255; i++) {

         /*--
            Process big buckets, starting with the least full.
         --*/
         ss = runningOrder[i];

         /*--
            Complete the big bucket [ss] by quicksorting
            any unsorted small buckets [ss, j].  Hopefully
            previous pointer-scanning phases have already
            completed many of the small buckets [ss, j], so
            we don't have to sort them at all.
         --*/
         for (j = 0; j <= 255; j++) {
            sb = (ss << 8) + j;
            if ( ! (ftab[sb] & SETMASK) ) {
               Int32 lo = ftab[sb]   & CLEARMASK;
               Int32 hi = (ftab[sb+1] & CLEARMASK) - 1;
               if (hi > lo) {
                  if (verbosity >= 4)
                     fprintf ( stderr,
                               "        qsort [0x%x, 0x%x]   done %d   this %d\n",
                               ss, j, numQSorted, hi - lo + 1 );
                  qSort3 ( lo, hi, 2 );
                  numQSorted += ( hi - lo + 1 );
                  if (workDone > workLimit && firstAttempt) return;
               }
               ftab[sb] |= SETMASK;
            }
         }

         /*--
            The ss big bucket is now done.  Record this fact,
            and update the quadrant descriptors.  Remember to
            update quadrants in the overshoot area too, if
            necessary.  The "if (i < 255)" test merely skips
            this updating for the last bucket processed, since
            updating for the last bucket is pointless.
         --*/
         bigDone[ss] = True;

         if (i < 255) {
            Int32 bbStart  = ftab[ss << 8] & CLEARMASK;
            Int32 bbSize   = (ftab[(ss+1) << 8] & CLEARMASK) - bbStart;
            Int32 shifts   = 0;

            while ((bbSize >> shifts) > 65534) shifts++;

            for (j = 0; j < bbSize; j++) {
               Int32 a2update     = zptr[bbStart + j];
               UInt16 qVal        = (UInt16)(j >> shifts);
               quadrant[a2update] = qVal;
               if (a2update < NUM_OVERSHOOT_BYTES)
                  quadrant[a2update + last + 1] = qVal;
            }

            if (! ( ((bbSize-1) >> shifts) <= 65535 )) panic ( "sortIt" );
         }

         /*--
            Now scan this big bucket so as to synthesise the
            sorted order for small buckets [t, ss] for all t != ss.
         --*/
         for (j = 0; j <= 255; j++)
            copy[j] = ftab[(j << 8) + ss] & CLEARMASK;

         for (j = ftab[ss << 8] & CLEARMASK;
              j < (ftab[(ss+1) << 8] & CLEARMASK);
              j++) {
            c1 = block[zptr[j]-1];
            if ( ! bigDone[c1] ) {
               zptr[copy[c1]] = zptr[j] == 0 ? last : zptr[j] - 1;
               copy[c1] ++;
            }
         }

         for (j = 0; j <= 255; j++) ftab[(j << 8) + ss] |= SETMASK;
      }
      if (verbosity >= 4)
         fprintf ( stderr, "        %d pointers, %d sorted, %d scanned\n",
                           last+1, numQSorted, (last+1) - numQSorted );
   }
}
