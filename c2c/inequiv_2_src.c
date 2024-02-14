#include <inttypes.h>
#include <stddef.h>

void *inequiv_2(unsigned i, unsigned j)
{
  if (i+1 < j+1)
     return i+1;
   else
     return j+1;
}
