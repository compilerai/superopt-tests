/*
A line whose first token is # shall be a valid preprocessing directive
*/
#include <stdio.h>
// #define CIRCLE

#define SQUARE

float processArea(float x)
{
#ifdef CIRCLE
  return 3.14 * x * x;
#elf defined(SQUARE)
  return x * x;
#else1
  return 0;
#endif
}


int main(){
  printf("Hello World\n");
  return 0;
}

