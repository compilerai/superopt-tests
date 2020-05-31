#include"eqchecker_helper.h"
/* PR c/19449 */

extern void Mymyabort (void);

int y;
int z = __builtin_choose_expr (!__builtin_constant_p (y), 3, 4);

int
foo (int x)
{
  return __builtin_choose_expr (!__builtin_constant_p (x), 3, y++);
}

int
main ()
{
  if (y || z != 3 || foo (4) != 3)
    Mymyabort ();
  return 0;
}
