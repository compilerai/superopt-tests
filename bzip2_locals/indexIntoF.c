#define UInt32  unsigned int
#define Int32   int
#define UInt16  unsigned short
#define UChar   unsigned char
#define Bool   unsigned char
#define True   1
#define False  0


Int32 indexIntoF ( Int32 indx, Int32 *cftab )
{
   Int32 nb, na, mid;
   nb = 0;
   na = 256;
   do {
      mid = (nb + na) >> 1;
      if (indx >= cftab[mid]) nb = mid; else na = mid;
   }
   while (na - nb != 1);
   return nb;
}
