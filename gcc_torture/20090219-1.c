#include"eqchecker_helper.h"
/* On ARM, BAR used to get a bogus number in E due to stack
   misalignment.  */

extern void Mymyabort (void);
extern void exit (int);

void
foo (void)
{
  int f = 0;

  void bar (int a, int b, int c, int d, int e)
    {
      if (e != 0)
	{
	  f = 1;
	  Mymyabort ();
	}
    }

  bar (0, 0, 0, 0, 0);
}

int
main (void)
{
  foo ();
  exit (0);
}
