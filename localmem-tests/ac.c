#include <alloca.h>

int MYmystrlen(char* s);
int write(int, int* a, int n);

int ac(char* s, int fd, int* a)
{
  int n;
  if (!s || (n = MYmystrlen(s)) <= 0)
    return 0;
  if (!a) {
    a = alloca(sizeof(int)*n);
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] + 32;
  }
  return write(fd, a, n);
}
