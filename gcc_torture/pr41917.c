#include"eqchecker_helper.h"
/* PR rtl-optimization/41917 */

extern void Mymyabort (void);
unsigned int a = 1;

int
main (void)
{
  unsigned int b, c, d;

  if (sizeof (int) != 4 || (int) 0xc7d24b5e > 0)
    return 0;

  c = 0xc7d24b5e;
  d = a | -2;
  b = (d == 0) ? c : (c % d);
  if (b != c)
    Mymyabort ();

  return 0;
}
