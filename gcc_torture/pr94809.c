#include"eqchecker_helper.h"
/* PR tree-optimization/94809 */

int
main ()
{
  int a = 0;
  unsigned long long one = 1;
  ((-1ULL / one) < a++, one);
  if (a != 1)
    Mymyabort ();
  return 0;
}
