/* List manipulations */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void *MYmymalloc(size_t size);
int MYmyprintf(const char *format, ...);

struct list { int hd; struct list * tl; };

struct list * buildlist(int n)
{
  struct list * r;
  if (n < 0) return NULL;
  r = MYmymalloc(sizeof(struct list));
  r->hd = n;
  r->tl = buildlist(n - 1);
  return r;
}

struct list * reverselist (struct list * l)
{
  struct list * r, * r2;
  for (r = NULL; l != NULL; l = l->tl) {
    r2 = MYmymalloc(sizeof(struct list));
    r2->hd = l->hd;
    r2->tl = r;
    r = r2;
  }
  return r;
}

struct list * reverse_inplace(struct list * l)
{
  struct list * prev, * next;

  prev = NULL;
  while (l != NULL) {
    next = l->tl;
    l->tl = prev;
    prev = l;
    l = next;
  }
  return prev;
}

int checklist(int n, struct list * l)
{
  int i;
  for (i = 0; i <= n; i++) {
    if (l == NULL) return 0;
    if (l->hd != i) return 0;
    l = l->tl;
  }
  return (l == NULL);
}

int main(int argc, char ** argv)
{
  int n, niter, i;
  struct list * l;

  if (argc >= 2) n = MYmyatoi(argv[1]); else n = 1000;
  if (argc >= 3) niter = MYmyatoi(argv[1]); else niter = 100000;
  l = buildlist(n);
  if (checklist(n, reverselist(l))) {
    MYmyprintf("OK\n");
  } else {
    goto BUG;
  }

  for (i = 0; i < 2*niter + 1; i++) {
    l = reverse_inplace(l);
  }
  if (checklist(n, l)) {
    MYmyprintf("OK\n");
  } else {
    goto BUG;
  }
  
  return 0;
  BUG:
    MYmyprintf("Bug!\n");
    return 2;
}
