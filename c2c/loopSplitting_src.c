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
  for (int i = 0; i < LEN; ++i) {
    if (i < mid) sum += c[a[i]];
    if (i >= mid) sum += b[i];
  }
  return sum;
}
