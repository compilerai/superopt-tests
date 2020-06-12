#include"eqchecker_helper.h"
/* PR middle-end/41935 */

extern void Mymyabort (void);

long int
foo (int n, int i, int j)
{
  typedef int T[n];
  struct S { int a; T b[n]; };
  return __builtin_offsetof (struct S, b[i][j]);
}

int
main (void)
{
  typedef int T[5];
  struct S { int a; T b[5]; };
  if (foo (5, 2, 3)
      != __builtin_offsetof (struct S, b) + (5 * 2 + 3) * sizeof (int))
    Mymyabort ();
  if (foo (5, 5, 5)
      != __builtin_offsetof (struct S, b) + (5 * 5 + 5) * sizeof (int))
    Mymyabort ();
  return 0;
}
