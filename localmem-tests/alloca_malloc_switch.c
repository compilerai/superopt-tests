#include <alloca.h>

int MYmystrlen(char* s);
char* MYmymalloc(int n);
void MYmyfree(char* a);
void foo(void*);
int write(int fd, char* a, int n);

void alloca_malloc_switch_simple(int n)
{
  if (n <= 0)
    return;
  char* a;
  if (n < 4096) {
    a = alloca(n);
  } else {
    a = MYmymalloc(n);
    if (!a) return;
  }
  foo(a);
  if (!(n < 4096))
    MYmyfree(a);
}

/*
int alloca_malloc_switch(char* s, int fd)
{
  if (!s)
    return 0;
  int n = MYmystrlen(s);
  char* a;
  if (n < 4096) {
    a = alloca(n);
  } else {
    a = MYmymalloc(n);
    if (!a) return 0;
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] ^ 1;
  }
  int ret = write(fd, a, n);
  if (!(n < 4096))
    MYmyfree(a);
  return ret;
}
*/
