#include"eqchecker_helper.h"
/* PR middle-end/52209 */

extern void Mymyabort (void);
struct S0 { int f2 : 1; } c;
int b;

int
main ()
{
  b = -1 ^ c.f2;
  if (b != -1)
    Mymyabort ();
  return 0;
}
