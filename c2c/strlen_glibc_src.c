#include <stddef.h>

size_t strlen_glibc(char *s)
{
  char *p ;
  for (p = s; *p; ++p);
  return p-s ;
}

