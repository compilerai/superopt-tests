#include <stdio.h>

#define UInt32  unsigned int
#define Int32   int
#define UInt16  unsigned short
#define UChar   unsigned char
#define Bool   unsigned char
#define True   1
#define False  0

#define N_GROUPS 6
#define G_SIZE   50
#define N_ITERS  4

#define MAX_ALPHA_SIZE 258

/*---------------------------------------------*/
#define LESSER_ICOST  0
#define GREATER_ICOST 15

UChar len  [N_GROUPS][MAX_ALPHA_SIZE];

UInt32  bytesIn, bytesOut;
Int32   verbosity;
Bool  inUse[256];
Int32 nInUse;

#define MAX_SELECTORS (2 + (900000 / G_SIZE))

UChar selector   [MAX_SELECTORS];
UChar selectorMtf[MAX_SELECTORS];

Int32 nMTF;
Int32 mtfFreq[MAX_ALPHA_SIZE];

UChar    *block;    /*-- compress   --*/
Int32    *zptr;     /*-- compress   --*/ 
UInt16   *szptr;    /*-- overlays zptr ---*/
Int32  last;

/*-- compress only --*/
Int32  code [N_GROUPS][MAX_ALPHA_SIZE];
Int32  rfreq[N_GROUPS][MAX_ALPHA_SIZE];



// 4 local arrays
void sendMTFValues ( void )
{
   Int32 v, t, i, j, gs, ge, totc, bt, bc, iter;
   Int32 nSelectors, alphaSize, minLen, maxLen, selCtr;
   Int32 nGroups, nBytes;

   /*--
   UChar  len [N_GROUPS][MAX_ALPHA_SIZE];
   is a global since the decoder also needs it.

   Int32  code[N_GROUPS][MAX_ALPHA_SIZE];
   Int32  rfreq[N_GROUPS][MAX_ALPHA_SIZE];
   are also globals only used in this proc.
   Made global to keep stack frame size small.
   --*/


   UInt16 cost[N_GROUPS];
   Int32  fave[N_GROUPS];

   if (verbosity >= 3)
      fprintf ( stderr, 
                "      %d in block, %d after MTF & 1-2 coding, %d+2 syms in use\n", 
                last+1, nMTF, nInUse );

   alphaSize = nInUse+2;
   for (t = 0; t < N_GROUPS; t++)
      for (v = 0; v < alphaSize; v++)
         len[t][v] = GREATER_ICOST;

   /*--- Decide how many coding tables to use ---*/
   if (nMTF <= 0) panic ( "sendMTFValues(0)" );
   if (nMTF < 200) nGroups = 2; else
   if (nMTF < 800) nGroups = 4; else
                   nGroups = 6;

   /*--- Generate an initial set of coding tables ---*/
   { 
      Int32 nPart, remF, tFreq, aFreq;

      nPart = nGroups;
      remF  = nMTF;
      gs = 0;
      while (nPart > 0) {
         tFreq = remF / nPart;
         ge = gs-1;
         aFreq = 0;
         while (aFreq < tFreq && ge < alphaSize-1) {
            ge++;
            aFreq += mtfFreq[ge];
         }

         if (ge > gs 
             && nPart != nGroups && nPart != 1 
             && ((nGroups-nPart) % 2 == 1)) {
            aFreq -= mtfFreq[ge];
            ge--;
         }

         // XXX commented out float
         // if (verbosity >= 3)
         //    fprintf ( stderr, 
         //              "      initial group %d, [%d .. %d], has %d syms (%4.1f%%)\n",
         //                      nPart, gs, ge, aFreq, 
         //                      (100.0 * (float)aFreq) / (float)nMTF );
 
         for (v = 0; v < alphaSize; v++)
            if (v >= gs && v <= ge) 
               len[nPart-1][v] = LESSER_ICOST; else
               len[nPart-1][v] = GREATER_ICOST;
 
         nPart--;
         gs = ge+1;
         remF -= aFreq;
      }
   }

   /*--- 
      Iterate up to N_ITERS times to improve the tables.
   ---*/
   nSelectors = 0; /* added to avoid undef value in llvm */
   for (iter = 0; iter < N_ITERS; iter++) {

      for (t = 0; t < nGroups; t++) fave[t] = 0;

      for (t = 0; t < nGroups; t++)
         for (v = 0; v < alphaSize; v++)
            rfreq[t][v] = 0;

      nSelectors = 0;
      totc = 0;
      gs = 0;
      while (True) {

         /*--- Set group start & end marks. --*/
         if (gs >= nMTF) break;
         ge = gs + G_SIZE - 1; 
         if (ge >= nMTF) ge = nMTF-1;

         /*-- 
            Calculate the cost of this group as coded
            by each of the coding tables.
         --*/
         for (t = 0; t < nGroups; t++) cost[t] = 0;

         if (nGroups == 6) {
            register UInt16 cost0, cost1, cost2, cost3, cost4, cost5;
            cost0 = cost1 = cost2 = cost3 = cost4 = cost5 = 0;
            for (i = gs; i <= ge; i++) { 
               UInt16 icv = szptr[i];
               cost0 += len[0][icv];
               cost1 += len[1][icv];
               cost2 += len[2][icv];
               cost3 += len[3][icv];
               cost4 += len[4][icv];
               cost5 += len[5][icv];
            }
            cost[0] = cost0; cost[1] = cost1; cost[2] = cost2;
            cost[3] = cost3; cost[4] = cost4; cost[5] = cost5;
         } else {
            for (i = gs; i <= ge; i++) { 
               UInt16 icv = szptr[i];
               for (t = 0; t < nGroups; t++) cost[t] += len[t][icv];
            }
         }
 
         /*-- 
            Find the coding table which is best for this group,
            and record its identity in the selector table.
         --*/
         bc = 999999999; bt = -1;
         for (t = 0; t < nGroups; t++)
            if (cost[t] < bc) { bc = cost[t]; bt = t; };
         totc += bc;
         fave[bt]++;
         selector[nSelectors] = bt;
         nSelectors++;

         /*-- 
            Increment the symbol frequencies for the selected table.
          --*/
         for (i = gs; i <= ge; i++)
            rfreq[bt][ szptr[i] ]++;

         gs = ge+1;
      }
      if (verbosity >= 3) {
         fprintf ( stderr, 
                   "      pass %d: size is %d, grp uses are ", 
                   iter+1, totc/8 );
         for (t = 0; t < nGroups; t++)
            fprintf ( stderr, "%d ", fave[t] );
         // XXX commented out the following line to avoid rodata-map collision
         // fprintf ( stderr, "\n" );
      }

      /*--
        Recompute the tables based on the accumulated frequencies.
      --*/
      for (t = 0; t < nGroups; t++)
         hbMakeCodeLengths ( &len[t][0], &rfreq[t][0], alphaSize, 20 );
   }


   if (!(nGroups < 8)) panic ( "sendMTFValues(1)" );
   if (!(nSelectors < 32768 &&
         nSelectors <= (2 + (900000 / G_SIZE))))
                       panic ( "sendMTFValues(2)" );


   /*--- Compute MTF values for the selectors. ---*/
   {
      UChar pos[N_GROUPS], ll_i, tmp2, tmp;
      for (i = 0; i < nGroups; i++) pos[i] = i;
      for (i = 0; i < nSelectors; i++) {
         ll_i = selector[i];
         j = 0;
         tmp = pos[j];
         while ( ll_i != tmp ) {
            j++;
            tmp2 = tmp;
            tmp = pos[j];
            pos[j] = tmp2;
         };
         pos[0] = tmp;
         selectorMtf[i] = j;
      }
   };

   /*--- Assign actual codes for the tables. --*/
   for (t = 0; t < nGroups; t++) {
      minLen = 32;
      maxLen = 0;
      for (i = 0; i < alphaSize; i++) {
         if (len[t][i] > maxLen) maxLen = len[t][i];
         if (len[t][i] < minLen) minLen = len[t][i];
      }
      if (maxLen > 20) panic ( "sendMTFValues(3)" );
      if (minLen < 1)  panic ( "sendMTFValues(4)" );
      hbAssignCodes ( &code[t][0], &len[t][0], 
                      minLen, maxLen, alphaSize );
   }

   /*--- Transmit the mapping table. ---*/
   { 
      Bool inUse16[16];
      for (i = 0; i < 16; i++) {
          inUse16[i] = False;
          for (j = 0; j < 16; j++)
             if (inUse[i * 16 + j]) inUse16[i] = True;
      }
     
      nBytes = bytesOut;
      for (i = 0; i < 16; i++)
         if (inUse16[i]) bsW(1,1); else bsW(1,0);

      for (i = 0; i < 16; i++)
	if (inUse16[i]) {
	  for (j = 0; j < 16; j++) {
	    if (inUse[i * 16 + j]) {
	      bsW(1,1);
	    } else {
	      bsW(1,0);
	    }
	  }
	}

      if (verbosity >= 3) 
         fprintf ( stderr, "      bytes: mapping %d, ", bytesOut-nBytes );
   }

   /*--- Now the selectors. ---*/
   nBytes = bytesOut;
   bsW ( 3, nGroups );
   bsW ( 15, nSelectors );
   for (i = 0; i < nSelectors; i++) { 
      for (j = 0; j < selectorMtf[i]; j++) bsW(1,1);
      bsW(1,0);
   }
   if (verbosity >= 3)
      fprintf ( stderr, "selectors %d, ", bytesOut-nBytes );

   /*--- Now the coding tables. ---*/
   nBytes = bytesOut;

   for (t = 0; t < nGroups; t++) {
      Int32 curr = len[t][0];
      bsW ( 5, curr );
      for (i = 0; i < alphaSize; i++) {
         while (curr < len[t][i]) { bsW(2,2); curr++; /* 10 */ };
         while (curr > len[t][i]) { bsW(2,3); curr--; /* 11 */ };
         bsW ( 1, 0 );
      }
   }

   if (verbosity >= 3)
      fprintf ( stderr, "code lengths %d, ", bytesOut-nBytes );

   /*--- And finally, the block data proper ---*/
   nBytes = bytesOut;
   selCtr = 0;
   gs = 0;
   while (True) {
      if (gs >= nMTF) break;
      ge = gs + G_SIZE - 1; 
      if (ge >= nMTF) ge = nMTF-1;
      for (i = gs; i <= ge; i++) { 
         #if DEBUG
            assert (selector[selCtr] < nGroups);
         #endif
         bsW ( len  [selector[selCtr]] [szptr[i]],
               code [selector[selCtr]] [szptr[i]] );
      }

      gs = ge+1;
      selCtr++;
   }
   if (!(selCtr == nSelectors)) panic ( "sendMTFValues(5)" );

   if (verbosity >= 3)
      fprintf ( stderr, "codes %d\n", bytesOut-nBytes );
}



