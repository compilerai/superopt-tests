#define UInt32  unsigned int
#define Int32   int
#define UInt16  unsigned short
#define UChar   unsigned char
#define Bool   unsigned char
#define True   1
#define False  0

#define MAX_ALPHA_SIZE 258
#define RUNA 0
#define RUNB 1

Int32 nInUse;
UChar unseqToSeq[256];
Int32 nMTF;
Int32 mtfFreq[MAX_ALPHA_SIZE];

UChar    *block;    /*-- compress   --*/
Int32    *zptr;     /*-- compress   --*/ 
UInt16   *szptr;    /*-- overlays zptr ---*/
Int32  last;

void makeMaps ( void );

// 1 local array
void generateMTFValues ( void )
{
   UChar  yy[256];
   Int32  i, j;
   UChar  tmp;
   UChar  tmp2;
   Int32  zPend;
   Int32  wr;
   Int32  EOB;

   makeMaps();
   EOB = nInUse+1;

   for (i = 0; i <= EOB; i++) mtfFreq[i] = 0;

   wr = 0;
   zPend = 0;
   for (i = 0; i < nInUse; i++) yy[i] = (UChar) i;
   

   for (i = 0; i <= last; i++) {
      UChar ll_i;

      #if DEBUG
         assert (wr <= i);
      #endif

      ll_i = unseqToSeq[block[zptr[i] - 1]];
      #if DEBUG
         assert (ll_i < nInUse);
      #endif

      j = 0;
      tmp = yy[j];
      while ( ll_i != tmp ) {
         j++;
         tmp2 = tmp;
         tmp = yy[j];
         yy[j] = tmp2;
      };
      yy[0] = tmp;

      if (j == 0) {
         zPend++;
      } else {
         if (zPend > 0) {
            zPend--;
            while (True) {
               switch (zPend % 2) {
                  case 0: szptr[wr] = RUNA; wr++; mtfFreq[RUNA]++; break;
                  case 1: szptr[wr] = RUNB; wr++; mtfFreq[RUNB]++; break;
               };
               if (zPend < 2) break;
               zPend = (zPend - 2) / 2;
            };
            zPend = 0;
         }
         szptr[wr] = j+1; wr++; mtfFreq[j+1]++;
      }
   }

   if (zPend > 0) {
      zPend--;
      while (True) {
         switch (zPend % 2) {
            case 0:  szptr[wr] = RUNA; wr++; mtfFreq[RUNA]++; break;
            case 1:  szptr[wr] = RUNB; wr++; mtfFreq[RUNB]++; break;
         };
         if (zPend < 2) break;
         zPend = (zPend - 2) / 2;
      };
   }

   szptr[wr] = EOB; wr++; mtfFreq[EOB]++;

   nMTF = wr;
}
