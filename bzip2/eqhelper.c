#include <stdlib.h>
#include <string.h>

void *MYmymemcpy(void *dest, const void *src, size_t n)
{
  memcpy(dest, src, n);
}

void *MYmymemset(void *s, int c, size_t n)
{
  memset(s, c, n);
}

void* MYmymalloc(size_t n)
{
  return malloc(n);
}

void MYmyexit(int n)
{
  exit(n);
}
