#include"eqchecker_helper.h"
/* PR target/60941 */
/* Reported by Martin Husemann <martin@netbsd.org> */

extern void Mymyabort (void);

static void __attribute__((noinline))
set (unsigned long *l)
{
  *l = 31;
}

int main (void)
{
  unsigned long l;
  int i;

  set (&l);
  i = (int) l;
  l = (unsigned long)(2U << i);
  if (l != 0)
    Mymyabort ();
  return 0;
}
