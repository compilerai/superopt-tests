#include <inttypes.h>

int sum2d(int* arr[], int m, int n)
{
  int ret = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      ret += arr[i][j];
  return ret;
}
