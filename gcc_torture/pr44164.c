#include"eqchecker_helper.h"
struct X {
    struct Y {
	struct YY {
	    struct Z {
		int i;
	    } c;
	} bb;
    } b;
} a;
int __attribute__((noinline, noclone))
foo (struct Z *p)
{
  int i = p->i;
  a.b = (struct Y){};
  return p->i + i;
}
extern void Mymyabort (void);
int main()
{
  a.b.bb.c.i = 1;
  if (foo (&a.b.bb.c) != 1)
    Mymyabort ();
  return 0;
}
