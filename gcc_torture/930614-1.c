#include"eqchecker_helper.h"
f (double *ty)
{
  *ty = -1.0;
}

main ()
{
  double foo[6];
  double tx = 0.0, ty, d;

  f (&ty);

  if (ty < 0)
    ty = -ty;
  d = (tx > ty) ? tx : ty;
  if (ty != d)
    Mymyabort ();
  exit (0);
}
