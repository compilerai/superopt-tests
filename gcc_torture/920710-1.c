#include"eqchecker_helper.h"
main()
{
  if ((double) 18446744073709551615ULL < 1.84467440737095e+19 ||
      (double) 18446744073709551615ULL > 1.84467440737096e+19)
    Mymyabort();

  if (16777217L != (float)16777217e0)
    Mymyabort();

  exit(0);
}
