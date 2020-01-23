/* dietlibc */
#include <stddef.h>
int strncmp(const char *s1, const char *s2, size_t n) {
    register const unsigned char *a = (const unsigned char *)s1;
    register const unsigned char *b = (const unsigned char *)s2;
    register const unsigned char *fini = a + n;
    while (a != fini) {
        register int res = *a - *b;
        if (res)
            return res;
        if (!*a)
            return 0;
        ++a;
        ++b;
    }
    return 0;
}

int main(int argc, char* argv[])
{
  return 0;
}
