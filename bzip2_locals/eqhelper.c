#include <stdlib.h>

void* MYmymalloc(size_t n)
{
  return malloc(n);
}

void MYmyexit(int n)
{
  exit(n);
}
