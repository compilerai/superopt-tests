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

UChar    *block;    /*-- compress   --*/
Int32    *zptr;     /*-- compress   --*/ 

Int32  workDone;
Int32  workLimit;
Bool   firstAttempt;

/*---------------------------------------------*/
/*--
   The following is an implementation of
   an elegant 3-way quicksort for strings,
   described in a paper "Fast Algorithms for
   Sorting and Searching Strings", by Robert
   Sedgewick and Jon L. Bentley.
--*/

#define swap(lv1, lv2) \
   { Int32 tmp = lv1; lv1 = lv2; lv2 = tmp; }

void vswap ( Int32 p1, Int32 p2, Int32 n );
//{
//   while (n > 0) {
//      swap(zptr[p1], zptr[p2]);
//      p1++; p2++; n--;
//   }
//}

UChar med3 ( UChar a, UChar b, UChar c );
//{
//   UChar t;
//   if (a > b) { t = a; a = b; b = t; };
//   if (b > c) { t = b; b = c; c = t; };
//   if (a > b)          b = a;
//   return b;
//}


#define min(a,b) ((a) < (b)) ? (a) : (b)

typedef
   struct { Int32 ll; Int32 hh; Int32 dd; }
   StackElem;

#define push(lz,hz,dz) { stack[sp].ll = lz; \
                         stack[sp].hh = hz; \
                         stack[sp].dd = dz; \
                         sp++; }

#define pop(lz,hz,dz) { sp--;               \
                        lz = stack[sp].ll;  \
                        hz = stack[sp].hh;  \
                        dz = stack[sp].dd; }

#define SMALL_THRESH 20
#define DEPTH_THRESH 10

/*--
   If you are ever unlucky/improbable enough
   to get a stack overflow whilst sorting,
   increase the following constant and try
   again.  In practice I have never seen the
   stack go above 27 elems, so the following
   limit seems very generous.
--*/
#define QSORT_STACK_SIZE 1000


// 1 local array
void qSort3 ( Int32 loSt, Int32 hiSt, Int32 dSt )
{
   Int32 unLo, unHi, ltLo, gtHi, med, n, m;
   Int32 sp, lo, hi, d;
   StackElem stack[QSORT_STACK_SIZE];

   sp = 0;
   push ( loSt, hiSt, dSt );

   while (sp > 0) {

      if (sp >= QSORT_STACK_SIZE) panic ( "stack overflow in qSort3" );

      pop ( lo, hi, d );

      if (hi - lo < SMALL_THRESH || d > DEPTH_THRESH) {
         simpleSort ( lo, hi, d );
         if (workDone > workLimit && firstAttempt) return;
         continue;
      }

      med = med3 ( block[zptr[ lo         ]+d],
                   block[zptr[ hi         ]+d],
                   block[zptr[ (lo+hi)>>1 ]+d] );

      unLo = ltLo = lo;
      unHi = gtHi = hi;

      while (True) {
         while (True) {
            if (unLo > unHi) break;
            n = ((Int32)block[zptr[unLo]+d]) - med;
            if (n == 0) { swap(zptr[unLo], zptr[ltLo]); ltLo++; unLo++; continue; };
            if (n >  0) break;
            unLo++;
         }
         while (True) {
            if (unLo > unHi) break;
            n = ((Int32)block[zptr[unHi]+d]) - med;
            if (n == 0) { swap(zptr[unHi], zptr[gtHi]); gtHi--; unHi--; continue; };
            if (n <  0) break;
            unHi--;
         }
         if (unLo > unHi) break;
         swap(zptr[unLo], zptr[unHi]); unLo++; unHi--;
      }
      #if DEBUG
         assert (unHi == unLo-1);
      #endif

      if (gtHi < ltLo) {
         push(lo, hi, d+1 );
         continue;
      }

      n = min(ltLo-lo, unLo-ltLo); vswap(lo, unLo-n, n);
      m = min(hi-gtHi, gtHi-unHi); vswap(unLo, hi-m+1, m);

      n = lo + unLo - ltLo - 1;
      m = hi - (gtHi - unHi) + 1;

      push ( lo, n, d );
      push ( n+1, m-1, d+1 );
      push ( m, hi, d );
   }
}
