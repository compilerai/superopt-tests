#include <stddef.h>

int ifswitch(int arr[], size_t n, int def)
{
  int ret = 0;
  for (size_t i = 0; i < n; ++i) {
    if (arr[i] == 0) {
      ret += def;
    } else if (arr[i] == -1) {
      ret += -def;
    } else {
      ret += arr[i];
    }
  }
  return ret;
}
