#include"eqchecker_helper.h"
struct S
{
  signed f0 : 16;
  unsigned f1 : 1;
};

int b;
static struct S c[] = {{-1, 0}, {-1, 0}};
struct S d;

int
main ()
{
  struct S e = c[0];
  d = e;
  if (d.f1 != 0)
    Mymyabort ();
  return 0;
}
