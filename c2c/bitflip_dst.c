#include <stddef.h>

void bitflip (int *array, unsigned int len)
{
  unsigned i=0;
  while((len-i)%4 != 0 && i < len) {
    array[i]^= 0xFFFFFFFF;
    i++;
  }
  while(i < len) {
    array[i]  ^= 0xFFFFFFFF;
    array[i+1]^= 0xFFFFFFFF;
    array[i+2]^= 0xFFFFFFFF;
    array[i+3]^= 0xFFFFFFFF;
    i += 4;
  }
}
