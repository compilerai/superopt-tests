#include"eqchecker_helper.h"
f (int b, int c)
{
  if (b != 0 && b != 1 && c != 0)
    b = 0;
  return b;
}

main ()
{
  if (!f (1, 2))
    Mymyabort();
  exit(0);
}
