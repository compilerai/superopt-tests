#include <inttypes.h>

#define LEN 1024
int a[LEN];

int sum1d()
{
  int ret = 0;
  for (int i = 0; i < LEN; i++)
    ret += a[i];
  return ret;
}
