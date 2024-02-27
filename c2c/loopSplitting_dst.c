#include <inttypes.h>

#define LEN 4096
int a[LEN];
int b[LEN];
int c[LEN];
int sum;

int loopSplitting()
{
  sum = 0;
  int mid = LEN/2;
  for (int i = 0; i < mid; ++i) {
    sum += c[a[i]];
  }
  for (int i = mid; i < LEN; i += 4) {
    sum += b[i];
    sum += b[i+1];
    sum += b[i+2];
    sum += b[i+3];
  }
  return sum;
}
