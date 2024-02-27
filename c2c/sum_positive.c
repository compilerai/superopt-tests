#include <inttypes.h>

int sum_positive(int* arr, int n)
{
  int ret = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] > 0)
      ret += arr[i];
  return ret;
}
