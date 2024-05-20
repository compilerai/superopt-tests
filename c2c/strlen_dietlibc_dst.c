/*
 * strlen implementation from dietlibc library
 * Location: dietlibc:lib/strlen.c
 */
#include <stddef.h>
#include <stdint.h>

#define __unlikely(s) (s)
#define __likely(s) (s)

#if ULONG_MAX == 0xFFFFFFFFFFFFFFFF
typedef uint64_t	word_t;
#else
typedef uint32_t	word_t;
#endif

static word_t const	magic = (word_t)(0x0101010101010101ull);

size_t strlen_dietlibc(const char *s)
{
  const char *t = s;
  word_t	word;

  // if (__unlikely(!s)) return 0;

  /* Byte compare up until word boundary */
  for (; ((unsigned long) t & (sizeof(magic)-1)); t++)
    if (!*t) return t - s;

  /* Word compare */
  while (1) {
    word = *((word_t const *) t);
    word = (word - magic) &~ word;
    word &= (magic << 7);
    if (!(__likely(word == 0))) {
      break;
    }
    t += sizeof word;
  }

  switch (sizeof(word)) {
  case 8:
    /* word & 0x8080808080808080 == word */
    word = (word - 1) & (magic << 8);
    word += (word << 32);
    word += (word << 16);
    word += (word << 8);
    t += word >> 56;
    break;

  case 4:
    /* word & 0x80808080 == word */
    word = (word - 1) & (magic << 10);
    word += (word << 8) + (word << 16);
    t += word >> 26;
    break;

  /* default: { char exc[sizeof(word)==8]; (void)exc; } */
  }
  return t - sizeof(word) - s;
}
