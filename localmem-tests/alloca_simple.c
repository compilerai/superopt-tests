#include <alloca.h>

int MYmyscanf(const char* fmt, ...);

int alloca_addr_taken_simple()
{
  int* a = (int*)alloca(sizeof(int));
  MYmyscanf("%d,", a);
  return *a;
}

int alloca_simple(int n)
{
  if (n < 1) {
    return 0;
  }
  int* p = (int*)alloca(n*sizeof(n));
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < n; ++i) {
    p[i] = i*i;
  }
  return p[0]*p[n-1];
}
