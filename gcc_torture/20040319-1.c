#include"eqchecker_helper.h"
int
blah (int zzz)
{
  int foo;
  if (zzz >= 0)
    return 1;
  foo = (zzz >= 0 ? (zzz) : -(zzz));
  return foo;
}

main()
{
  if (blah (-1) != 1)
    Mymyabort ();
  else
    exit (0);
}
