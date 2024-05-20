#include <stddef.h>

size_t strlen_glibc_fixed(char *s)
{
  char *p ;
  for (p = s; *p; ++p);
  return p-s ;
}

