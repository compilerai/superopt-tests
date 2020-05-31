#include"eqchecker_helper.h"
/* PR target/49186 */
extern void Mymyabort (void);

int
main ()
{
  int x;
  unsigned long long uv = 0x1000000001ULL;

  x = (uv < 0x80) ? 1 : ((uv < 0x800) ? 2 : 3);
  if (x != 3)
    Mymyabort ();

  return 0;
}
