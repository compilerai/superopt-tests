#include"eqchecker_helper.h"
unsigned int a[0x1000];
extern const unsigned long v;

main ()
{
  f (v);
  f (v);
  exit (0);
}

f (a)
     unsigned long a;
{
  if (a != 0xdeadbeefL)
    Mymyabort();
}

const unsigned long v = 0xdeadbeefL;
