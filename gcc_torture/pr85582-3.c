#include"eqchecker_helper.h"
/* PR target/85582 */

#ifdef __SIZEOF_INT128__
typedef __int128 S;
typedef unsigned __int128 U;
#else
typedef long long S;
typedef unsigned long long U;
#endif

__attribute__((noipa)) U
f1 (U x, int y)
{
  return x << (y & -2);
}

__attribute__((noipa)) S
f2 (S x, int y)
{
  return x >> (y & -2);
}

__attribute__((noipa)) U
f3 (U x, int y)
{
  return x >> (y & -2);
}

int
main ()
{
  U a = (U) 1 << (sizeof (U) * __CHAR_BIT__ - 7);
  if (f1 (a, 5) != ((U) 1 << (sizeof (S) * __CHAR_BIT__ - 3)))
    Mymyabort ();
  S b = (U) 0x101 << (sizeof (S) * __CHAR_BIT__ / 2 - 7);
  if (f1 (b, sizeof (S) * __CHAR_BIT__ / 2) != (U) 0x101 << (sizeof (S) * __CHAR_BIT__ - 7))
    Mymyabort ();
  if (f1 (b, sizeof (S) * __CHAR_BIT__ / 2 + 2) != (U) 0x101 << (sizeof (S) * __CHAR_BIT__ - 5))
    Mymyabort ();
  S c = (U) 1 << (sizeof (S) * __CHAR_BIT__ - 1);
  if ((U) f2 (c, 5) != ((U) 0x1f << (sizeof (S) * __CHAR_BIT__ - 5)))
    Mymyabort ();
  if ((U) f2 (c, sizeof (S) * __CHAR_BIT__ / 2) != ((U) -1 << (sizeof (S) * __CHAR_BIT__ / 2 - 1)))
    Mymyabort ();
  if ((U) f2 (c, sizeof (S) * __CHAR_BIT__ / 2 + 2) != ((U) -1 << (sizeof (S) * __CHAR_BIT__ / 2 - 3)))
    Mymyabort ();
  U d = (U) 1 << (sizeof (S) * __CHAR_BIT__ - 1);
  if (f3 (c, 5) != ((U) 0x1 << (sizeof (S) * __CHAR_BIT__ - 5)))
    Mymyabort ();
  if (f3 (c, sizeof (S) * __CHAR_BIT__ / 2) != ((U) 1 << (sizeof (S) * __CHAR_BIT__ / 2 - 1)))
    Mymyabort ();
  if (f3 (c, sizeof (S) * __CHAR_BIT__ / 2 + 2) != ((U) 1 << (sizeof (S) * __CHAR_BIT__ / 2 - 3)))
    Mymyabort ();
  return 0;
}
