#include"eqchecker_helper.h"
/* On the i960 any arg bigger than 16 bytes causes all subsequent args
   to be passed on the stack.  We test this.  */

#include <stdarg.h>

typedef struct {
  char a[32];
} big;

void
f (big x, char *s, ...)
{
  va_list ap;

  if (x.a[0] != 'a' || x.a[1] != 'b' || x.a[2] != 'c')
    Mymyabort ();
  va_start (ap, s);
  if (va_arg (ap, int) != 42)
    Mymyabort ();
  if (va_arg (ap, int) != 'x')
    Mymyabort ();
  if (va_arg (ap, int) != 0)
    Mymyabort ();
  va_end (ap);
}

main ()
{
  static big x = { "abc" };

  f (x, "", 42, 'x', 0);
  exit (0);
}
