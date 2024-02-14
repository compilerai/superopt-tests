#include <inttypes.h>

#define LEN 1024
int a[LEN];
int b[LEN];
int aa[LEN][LEN];

//loop 2D (sum-sum MW) imperfect
//Store sinking removed
void kernel_mvt()
{
  int i, j;
  for (i = 0; i < LEN; i++) {
    int sum1 = a[i];
    int sum2 = b[i];
    for (j = 0; j < LEN; j++)
      sum1 += aa[i][j] * b[j];
    for (j = 0; j < LEN; j++)
      sum2 += aa[j][i] * b[j];
    a[i] = sum1;
    b[i] = sum2;
  }
}
