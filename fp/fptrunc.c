#include <stdbool.h>
#include <stdlib.h>
struct foo { int data; struct foo* next; };
int dummy1, dummy2, dummy3;
int g_int;

float fptrunc(double x)
{
  return (float)x;
}

float fptruncl(long double x)
{
  return (float)x;
}
