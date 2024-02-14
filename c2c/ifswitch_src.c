#include <stddef.h>

int ifswitch(int arr[], size_t n, int def)
{
  int ret = 0;
  for (size_t i = 0; i < n; ++i) {
    switch (arr[i]) {
      case 0:
        ret += def;
        break;
      case -1:
        ret += -def;
        break;
      default:
        ret += arr[i];
        break;
    }
  }
  return ret;
}
