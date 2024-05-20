#include <stddef.h>

size_t strlen_dietlibc(char *s)
{
  char *p ;
  for (p = s; *p; ++p);
  return p-s ;
}

