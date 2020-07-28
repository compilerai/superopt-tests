#include"eqchecker_helper.h"
/* { dg-add-options stack_size } */

#include <string.h>

#if defined (STACK_SIZE)
#define MEMCPY_SIZE (STACK_SIZE / 3)
#else
#define MEMCPY_SIZE (1 << 17)
#endif


void *copy (void *o, const void *i, unsigned l)
{
  return memcpy (o, i, l);
}

main ()
{
  unsigned i;
  unsigned char src[MEMCPY_SIZE];
  unsigned char dst[MEMCPY_SIZE];

  for (i = 0; i < MEMCPY_SIZE; i++)
    src[i] = (unsigned char) i,  dst[i] = 0;

  (void) memcpy (dst, src, MEMCPY_SIZE / 128);

  for (i = 0; i < MEMCPY_SIZE / 128; i++)
    if (dst[i] != (unsigned char) i)
      Mymyabort ();

  (void) memset (dst, 1, MEMCPY_SIZE / 128);

  for (i = 0; i < MEMCPY_SIZE / 128; i++)
    if (dst[i] != 1)
      Mymyabort ();

  (void) memcpy (dst, src, MEMCPY_SIZE);

  for (i = 0; i < MEMCPY_SIZE; i++)
    if (dst[i] != (unsigned char) i)
      Mymyabort ();

  (void) memset (dst, 0, MEMCPY_SIZE);

  for (i = 0; i < MEMCPY_SIZE; i++)
    if (dst[i] != 0)
      Mymyabort ();

  (void) copy (dst, src, MEMCPY_SIZE / 128);

  for (i = 0; i < MEMCPY_SIZE / 128; i++)
    if (dst[i] != (unsigned char) i)
      Mymyabort ();

  (void) memset (dst, 0, MEMCPY_SIZE);

  (void) copy (dst, src, MEMCPY_SIZE);

  for (i = 0; i < MEMCPY_SIZE; i++)
    if (dst[i] != (unsigned char) i)
      Mymyabort ();

  exit (0);
}