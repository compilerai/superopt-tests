#include <stddef.h>

void bitflip (int *array, unsigned int len)
{
  for(unsigned int i = 0; i < len; ++i) {
    array[i] ^= 0xffffffff;
  }
}
