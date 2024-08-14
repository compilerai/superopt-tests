#include <inttypes.h>
#include <stddef.h>

unsigned inequiv_2(unsigned i, unsigned j)
{
  if (i < j)
    return i+1;
  else
    return j+1;
}
