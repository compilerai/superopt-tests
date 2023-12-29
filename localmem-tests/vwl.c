#include <stdarg.h>

int vwl(unsigned n, ...)
{
  unsigned i;
  va_list args;
  int ret = 0;

  va_start(args, n);
#pragma clang loop vectorize(disable) unroll(disable)
  for (i = 0; i < n; ++i) {
    if (i % 2 == 0)
      ret -= va_arg(args, int);
    else
      ret += va_arg(args, int);
  }
  va_end(args);

  return ret;
}
