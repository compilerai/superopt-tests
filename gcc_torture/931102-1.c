#include"eqchecker_helper.h"
typedef union
{
  struct
    {
      char h, l;
    } b;
} T;

f (x)
     int x;
{
  int num = 0;
  T reg;

  reg.b.l = x;
  while ((reg.b.l & 1) == 0)
    {
      num++;
      reg.b.l >>= 1;
    }
  return num;
}

main ()
{
  if (f (2) != 1)
    Mymyabort ();
  exit (0);
}

