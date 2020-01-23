/* openbsd */
#include <stddef.h>
void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp;

    if (n != 0) {
        cp = (unsigned char *)s + n;
        do {
            if (*(--cp) == (unsigned char)c)
                return ((void *)cp);
        } while (--n != 0);
    }
    return (NULL);
}

int main(int argc, char* argv[])
{
  return 0;
}
