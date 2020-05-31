#include"eqchecker_helper.h"
/* PR optimization/9325  */

#include <limits.h>

extern void Mymyabort (void);

int f1()
{
  return (int)2147483648.0f;
}

int f2()
{
  return (int)(float)(2147483647);
}

int main()
{
#if INT_MAX == 2147483647
  if (f1() != 2147483647)
    Mymyabort ();
  if (f2() != 2147483647)
    Mymyabort ();
#endif
  return 0;
}

