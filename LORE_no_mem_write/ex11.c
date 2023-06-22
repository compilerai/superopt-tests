#define LEN 32000
#define LEN1 3200
#define LEN2 1024
#define LEN3 256

#define TYPE int

__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],dd[LEN2][LEN2],tmp[LEN2][LEN2], aaa[LEN3][LEN3][LEN3], bbb[LEN3][LEN3][LEN3];
TYPE x,y;

int alpha, beta;
//loop 2D (sum-MW) imperfect
//Store sinking removed
void ex11()
//void kernel_gesummv()
{
  int i, j;
  for (i = 0; i < LEN2; i++)
  {
    int sum1 = 0;
    int sum2 = 0;
    for (j = 0; j < LEN2; j++)
    {
      sum1 += aa[i][j] * c[j];
      sum2 += bb[i][j] * c[j];
    }
    b[i] = alpha * sum1 + beta * sum2;
  }
}
