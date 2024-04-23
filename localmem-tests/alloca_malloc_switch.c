#include <alloca.h>

char* MYmymalloc(size_t n);
void MYmyfree(void* a);
int foo(void*);

int alloca_malloc_switch_acyclic(int n)
{
  if (n <= 0)
    return -1;
  int* p;
  if (n < 4096) {
    p = alloca(sizeof(int)*n);
  } else {
    p = (int*)MYmymalloc(sizeof(int)*n);
    if (!p) return -1;
  }
  int i = foo(p);
  int ret = n*p[i];
  if (!(n < 4096))
    MYmyfree((void*)p);
  return ret;
}

/*
int MYmystrlen(char* s);
int write(int fd, char* a, int n);
int alloca_malloc_switch_cyclic(char* s, int fd)
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
