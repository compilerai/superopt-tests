#define LEN 32000
#define LEN1 3200
#define LEN2 1024
#define LEN3 256

#define TYPE int

__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],dd[LEN2][LEN2],tmp[LEN2][LEN2], aaa[LEN3][LEN3][LEN3], bbb[LEN3][LEN3][LEN3];
TYPE x,y;

//3-way branch 1D loop
//MW
int ex107()
{

    #pragma GCC unroll 2
    for (int i = 0; i < LEN; i++) {
      if (d[i] < (TYPE)0.) {
        a[i] += b[i] * c[i];
      } else if (d[i] == (TYPE)0.) {
        a[i] += b[i] * b[i];
      } else {
        a[i] += c[i] * c[i];
      }   
    }   
  return 0;
}
