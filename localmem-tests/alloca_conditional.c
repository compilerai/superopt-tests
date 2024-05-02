#include <alloca.h>

int MYmystrlen(char* s);
int write(int, int* a, int n);
int scanf(const char*, ...);
int init();
void deinit(int*);
int bar(int*,int*,int*);


int alloca_conditional_simple(int fd, int n, char* a)
{
  if (!a) {
    a = alloca(sizeof(int)*n);
  }
  scanf("%s", a);
  return write(fd, (void*)a, n);
}

int alloca_conditional(char* s, int fd, int* a)
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

int alloca_conditional_3(int* p, int* q, int* r)
{
  if (!p) {
    p = alloca(sizeof(int));
    *p = init();
    if (!q) {
      q = alloca(sizeof(int));
      *q = init();
      if (!r) {
        r = alloca(sizeof(int));
        *r = init();
        *r += *p + *q;
        deinit(r);
      }
      *q += *p + *r;
      deinit(q);
    }
    *p += *q + *r;
    deinit(p);
  }
  int tmp = *p;
  *p = *q;
  *q = *r;
  *r = tmp;
  return bar(p, q, r);
}
