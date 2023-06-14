#include <stdbool.h>
#include <stdlib.h>

bool flcmp(long double x, long double y)
{
  return x < y;
}

long double fladd(long double x, long double y)
{
  return x + y;
}

long double flsub(long double x, long double y)
{
  return x - y;
}

long double flmul(long double x, long double y)
{
  return x * y;
}

long double fldiv(long double x, long double y)
{
  return x / y;
}
