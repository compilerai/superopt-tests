#include"eqchecker_helper.h"
/* PR middle-end/40057 */

extern void Mymyabort (void);

__attribute__((noinline)) int
foo (unsigned long long x)
{
  unsigned long long y = (x >> 31ULL) & 1ULL;
  if (y == 0ULL)
    return 0;
  return -1;
}

__attribute__((noinline)) int
bar (long long x)
{
  long long y = (x >> 31LL) & 1LL;
  if (y == 0LL)
    return 0;
  return -1;
}

int
main (void)
{
  if (sizeof (long long) != 8)
    return 0;
  if (foo (0x1682a9aaaULL))
    Mymyabort ();
  if (!foo (0x1882a9aaaULL))
    Mymyabort ();
  if (bar (0x1682a9aaaLL))
    Mymyabort ();
  if (!bar (0x1882a9aaaLL))
    Mymyabort ();
  return 0;
}
