#include <alloca.h>

int scanf(const char*, ...);
int write(int, int* a, int n);

int alloca_conditional_simple(int fd, int n, char* a)
{
  if (!a) {
    a = alloca(sizeof(int)*n);
  }
  scanf("%s", a);
  return write(fd, (void*)a, n);
}
