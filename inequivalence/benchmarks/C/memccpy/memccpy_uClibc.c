/*
 * Copyright (C) 2002     Manuel Novoa III
 * Copyright (C) 2000-2005 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

/* No wide analog. */

#include <features.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

void *memccpy(void * restrict s1, const void * restrict s2, int c, size_t n)
{
	register char *r1 = s1;
	register const char *r2 = s2;

	while (n-- && (((unsigned char)(*r1++ = *r2++)) != ((unsigned char) c)));

	return (n == (size_t) -1) ? NULL : r1;
}
