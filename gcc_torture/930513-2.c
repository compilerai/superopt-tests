#include"eqchecker_helper.h"
sub3 (i)
     const int *i;
{
}

eq (a, b)
{
  static int i = 0;
  if (a != i)
    Mymyabort ();
  i++;
}

main ()
{
  int i;

  for (i = 0; i < 4; i++)
    {
      const int j = i;
      int k;
      sub3 (&j);
      k = j;
      eq (k, k);
    }
  exit (0);
}