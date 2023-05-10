#include <alloca.h>

int MYmystrlen(char* s);
char* MYmymalloc(int n);
void MYmyDBG();
void MYmyfree(char* a);
int write(int fd, char* a, int n);

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
  for (int i = 0; i < n; ++i) {
    MYmyDBG(); // XXX
    a[i] = s[i] ^ 1;
  }
  int ret = write(fd, a, n);
  if (!(n < 4096))
    MYmyfree(a);
  return ret;
}
