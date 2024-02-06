#include <stdio.h>

#define UInt32  unsigned int
#define Int32   int
#define UInt16  unsigned short
#define UChar   unsigned char
#define Bool   unsigned char
#define True   1
#define False  0

#define MAX_ALPHA_SIZE 258
#define N_GROUPS 6
#define G_SIZE   50
#define MAX_SELECTORS (2 + (900000 / G_SIZE))

#define RUNA 0
#define RUNB 1

UInt32 bsR ( Int32 n );
UInt32 bsGetIntVS ( UInt32 numBits );
void recvDecodingTables ( void );
int fgetc (FILE*);
void    compressedStreamEOF   ( void );
void blockOverrun ();

Bool    smallMode;

Int32 nInUse;
UChar seqToUnseq[256];
UChar selector   [MAX_SELECTORS];

Int32 limit  [N_GROUPS][MAX_ALPHA_SIZE];
Int32 base   [N_GROUPS][MAX_ALPHA_SIZE];
Int32 perm   [N_GROUPS][MAX_ALPHA_SIZE];
Int32 minLens[N_GROUPS];

Int32  blockSize100k;

FILE*  bsStream;

UInt32 bsBuff;
Int32  bsLive;

UInt16   *ll16;     /*-- small decompress --*/

UChar    *ll8;      /*-- fast decompress  --*/

Int32   unzftab[256];
Int32  last;
Int32  origPtr;

/*---------------------------------------------*/
#define bsNEEDR(nz)                           \
{                                             \
   while (bsLive < nz) {                      \
      Int32 zzi = fgetc ( bsStream );         \
      if (zzi == EOF) compressedStreamEOF();  \
      bsBuff = (bsBuff << 8) | (zzi & 0xffL); \
      bsLive += 8;                            \
   }                                          \
}

/*---------------------------------------------*/
#define bsR1(vz)                              \
{                                             \
   bsNEEDR(1);                                \
   vz = (bsBuff >> (bsLive-1)) & 1;           \
   bsLive--;                                  \
}

/*---------------------------------------------*/
#define GET_MTF_VAL(lval)                 \
{                                         \
   Int32 zt, zn, zvec, zj;                \
   if (groupPos == 0) {                   \
      groupNo++;                          \
      groupPos = G_SIZE;                  \
   }                                      \
   groupPos--;                            \
   zt = selector[groupNo];                \
   zn = minLens[zt];                      \
   zvec = bsR ( zn );                     \
   while (zvec > limit[zt][zn]) {         \
      zn++; bsR1(zj);                     \
      zvec = (zvec << 1) | zj;            \
   };                                     \
   lval = perm[zt][zvec - base[zt][zn]];  \
}


/*---------------------------------------------*/
// 1 local array
void getAndMoveToFrontDecode ( void )
{
   UChar  yy[256];
   Int32  i, j, nextSym, limitLast;
   Int32  EOB, groupNo, groupPos;

   limitLast = 100000 * blockSize100k;
   origPtr   = bsGetIntVS ( 24 );

   recvDecodingTables();
   EOB      = nInUse+1;
   groupNo  = -1;
   groupPos = 0;

   /*--
      Setting up the unzftab entries here is not strictly
      necessary, but it does save having to do it later
      in a separate pass, and so saves a block's worth of
      cache misses.
   --*/
   for (i = 0; i <= 255; i++) unzftab[i] = 0;

   for (i = 0; i <= 255; i++) yy[i] = (UChar) i;

   last = -1;

   GET_MTF_VAL(nextSym);

   while (True) {

      if (nextSym == EOB) break;

      if (nextSym == RUNA || nextSym == RUNB) {
         UChar ch;
         Int32 s = -1;
         Int32 N = 1;
         do {
            if (nextSym == RUNA) s = s + (0+1) * N; else
            if (nextSym == RUNB) s = s + (1+1) * N;
            N = N * 2;
            GET_MTF_VAL(nextSym);
         }
            while (nextSym == RUNA || nextSym == RUNB);

         s++;
         ch = seqToUnseq[yy[0]];
         unzftab[ch] += s;

         if (smallMode)
            while (s > 0) {
               last++; 
               ll16[last] = ch;
               s--;
            }
         else
            while (s > 0) {
               last++;
               ll8[last] = ch;
               s--;
            };

         if (last >= limitLast) blockOverrun();
         continue;

      } else {

         UChar tmp;
         last++; if (last >= limitLast) blockOverrun();

         tmp = yy[nextSym-1];
         unzftab[seqToUnseq[tmp]]++;
         if (smallMode)
            ll16[last] = seqToUnseq[tmp]; else
            ll8[last]  = seqToUnseq[tmp];

         /*--
            This loop is hammered during decompression,
            hence the unrolling.

            for (j = nextSym-1; j > 0; j--) yy[j] = yy[j-1];
         --*/

         j = nextSym-1;
         for (; j > 3; j -= 4) {
            yy[j]   = yy[j-1];
            yy[j-1] = yy[j-2];
            yy[j-2] = yy[j-3];
            yy[j-3] = yy[j-4];
         }
         for (; j > 0; j--) yy[j] = yy[j-1];

         yy[0] = tmp;
         GET_MTF_VAL(nextSym);
         continue;
      }
   }
}
