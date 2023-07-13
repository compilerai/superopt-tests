#include <alloca.h>

int init();
void deinit(int*);
int bar(int*,int*,int*);

int alloca_unreal_1(int* p, int* q, int* r)
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
