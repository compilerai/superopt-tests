#include"eqchecker_helper.h"
struct tiny
{
  char c;
  char d;
  char e;
};

f (int n, struct tiny x, struct tiny y, struct tiny z, long l)
{
  if (x.c != 10)
    Mymyabort();
  if (x.d != 20)
    Mymyabort();
  if (x.e != 30)
    Mymyabort();

  if (y.c != 11)
    Mymyabort();
  if (y.d != 21)
    Mymyabort();
  if (y.e != 31)
    Mymyabort();

  if (z.c != 12)
    Mymyabort();
  if (z.d != 22)
    Mymyabort();
  if (z.e != 32)
    Mymyabort();

  if (l != 123)
    Mymyabort ();
}

main ()
{
  struct tiny x[3];
  x[0].c = 10;
  x[1].c = 11;
  x[2].c = 12;
  x[0].d = 20;
  x[1].d = 21;
  x[2].d = 22;
  x[0].e = 30;
  x[1].e = 31;
  x[2].e = 32;
  f (3, x[0], x[1], x[2], (long) 123);
  exit(0);
}

