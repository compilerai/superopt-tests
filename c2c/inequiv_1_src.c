#include <inttypes.h>
#include <stddef.h>

void *inequiv_1(void *dst, const void *src, int c)
{
  char *a = dst;
  const char *b = src;
  if (*b == c) {
    return (void *)a;
  }
  return 0;
}
