#include <stdbool.h>
#include <stdlib.h>
struct foo { int data; struct foo* next; };
int dummy1, dummy2, dummy3;
int g_int;

void foo(double);

double fpext(float x)
{
  double ret = (double)x;
  ret = ret * 2;
  //foo(ret);
  ret = ret / 3;
  return ret;
}

long double fpextl(float x)
{
  long double ret = (long double)x;
  ret = ret * 2;
  //foo(ret);
  ret = ret / 3;
  return ret;
}
