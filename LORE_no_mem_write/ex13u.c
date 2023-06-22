#define LEN 32000
#define LEN1 3200
#define LEN2 1024
#define LEN3 256

#define TYPE int

__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],dd[LEN2][LEN2],tmp[LEN2][LEN2], aaa[LEN3][LEN3][LEN3], bbb[LEN3][LEN3][LEN3];
TYPE x,y;

//loop 3D (2-sum MW) imperfect 
void ex13()
//void example14() 
{
  int k,j,i=0;
  int len = LEN2/2;
  for (k = 0; k < len; k++) {
    int sum = 0;
    for (i = 0; i < len; i++)
      #pragma GCC unroll 2
      for (j = 0; j < len; j++)
          sum += aa[i+k][j] * bb[i][j];

    a[k] = sum;
  }

}
