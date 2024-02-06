#define UInt32  unsigned int
#define Int32   int
#define UChar   unsigned char
#define Bool   unsigned char
#define True   1
#define False  0

#define MAX_ALPHA_SIZE 258
#define N_GROUPS 6
#define G_SIZE   50
#define MAX_SELECTORS (2 + (900000 / G_SIZE))

UInt32 bsR ( Int32 n );
void makeMaps ( void );
void hbCreateDecodeTables ( Int32 *limit,
                            Int32 *base,
                            Int32 *perm,
                            UChar *length,
                            Int32 minLen,
                            Int32 maxLen,
                            Int32 alphaSize );

UChar selectorMtf[MAX_SELECTORS];

Bool  inUse[256];
Int32 nInUse;
UChar selector   [MAX_SELECTORS];

UChar len  [N_GROUPS][MAX_ALPHA_SIZE];

Int32 limit  [N_GROUPS][MAX_ALPHA_SIZE];
Int32 base   [N_GROUPS][MAX_ALPHA_SIZE];
Int32 perm   [N_GROUPS][MAX_ALPHA_SIZE];
Int32 minLens[N_GROUPS];

// 2 local array
void recvDecodingTables ( void )
{
   Int32 i, j, t, nGroups, nSelectors, alphaSize;
   Int32 minLen, maxLen;
   Bool inUse16[16];

   /*--- Receive the mapping table ---*/
   for (i = 0; i < 16; i++)
      if (bsR(1) == 1) 
         inUse16[i] = True; else 
         inUse16[i] = False;

   for (i = 0; i < 256; i++) inUse[i] = False;

   for (i = 0; i < 16; i++)
      if (inUse16[i])
         for (j = 0; j < 16; j++)
            if (bsR(1) == 1) inUse[i * 16 + j] = True;

   makeMaps();
   alphaSize = nInUse+2;

   /*--- Now the selectors ---*/
   nGroups = bsR ( 3 );
   nSelectors = bsR ( 15 );
   for (i = 0; i < nSelectors; i++) {
      j = 0;
      while (bsR(1) == 1) j++;
      selectorMtf[i] = j;
   }

   /*--- Undo the MTF values for the selectors. ---*/
   {
      UChar pos[N_GROUPS], tmp, v;
      for (v = 0; v < nGroups; v++) pos[v] = v;
   
      for (i = 0; i < nSelectors; i++) {
         v = selectorMtf[i];
         tmp = pos[v];
         while (v > 0) { pos[v] = pos[v-1]; v--; }
         pos[0] = tmp;
         selector[i] = tmp;
      }
   }

   /*--- Now the coding tables ---*/
   for (t = 0; t < nGroups; t++) {
      Int32 curr = bsR ( 5 );
      for (i = 0; i < alphaSize; i++) {
         while (bsR(1) == 1) {
            if (bsR(1) == 0) curr++; else curr--;
         }
         len[t][i] = curr;
      }
   }

   /*--- Create the Huffman decoding tables ---*/
   for (t = 0; t < nGroups; t++) {
      minLen = 32;
      maxLen = 0;
      for (i = 0; i < alphaSize; i++) {
         if (len[t][i] > maxLen) maxLen = len[t][i];
         if (len[t][i] < minLen) minLen = len[t][i];
      }
      hbCreateDecodeTables ( 
         &limit[t][0], &base[t][0], &perm[t][0], &len[t][0],
         minLen, maxLen, alphaSize
      );
      minLens[t] = minLen;
   }
}
