#include <stdarg.h>

int variadic_with_loop(int n, ...)
{
  int i;
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

int foo(va_list ap);

int variadic_with_copy(int n, ...)
{
  int i;
  va_list start, args;
  int ret = 0;

  va_start(start, n);
  va_copy(args, start);
#pragma clang loop vectorize(disable) unroll(disable)
  for (i = 0; i < n; ++i) {
    if (i%2 == 0)
      ret -= va_arg(args, int);
    else
      ret += va_arg(args, int);
  }
  va_end(args);

  va_copy(args, start);
  ret += foo(args);
  va_end(args);
  va_end(start);

  return ret;
}
