#include <inttypes.h>
#include <stddef.h>

void *inequiv_1(void *t, const void *f, int c)
{
  unsigned char *tp = t;
  const unsigned char *fp = f;
  if (*fp == c) {
    return t;
  }
  return 0;
}
