#include"eqchecker_helper.h"
#include <stdarg.h>

va_double (int n, ...)
{
  va_list args;

  va_start (args, n);

  if (va_arg (args, double) != 3.141592)
    Mymyabort ();
  if (va_arg (args, double) != 2.71827)
    Mymyabort ();
  if (va_arg (args, double) != 2.2360679)
    Mymyabort ();
  if (va_arg (args, double) != 2.1474836)
    Mymyabort ();

  va_end (args);
}

va_long_double (int n, ...)
{
  va_list args;

  va_start (args, n);

  if (va_arg (args, long double) != 3.141592L)
    Mymyabort ();
  if (va_arg (args, long double) != 2.71827L)
    Mymyabort ();
  if (va_arg (args, long double) != 2.2360679L)
    Mymyabort ();
  if (va_arg (args, long double) != 2.1474836L)
    Mymyabort ();

  va_end (args);
}

main ()
{
  va_double (4, 3.141592, 2.71827, 2.2360679, 2.1474836);
  va_long_double (4, 3.141592L, 2.71827L, 2.2360679L, 2.1474836L);
  exit (0);
}
