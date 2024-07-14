#include <alloca.h>

// both alive_local() and dead_local() pass because the alloca is hoisted to the prologue in src
int alive_local(int n)
{
  int x = 0;
  if (n > 0 || n <= 0) {
    int p[10];
    x = (int)&p;
    // cannot have any anchor points in this block
  }
  return x;
}

int dead_local(int n)
{
  if (n > 0 && n <= 0) {
    int p[10];
    MYmyprintf("%p", p);
  }
  return 0;
}

// this fails because the syntactic alloc-dealloc pairing fails to lockstep correlate the unreachable path of the src full-pathset
int alive_alloca(int n)
{
  int* p = 0;
  if (n > 0 || n <= 0) {
    p = (int*)alloca(n*sizeof(n));
    // cannot have any anchor points in this block
  }
  MYmyprintf("%p", p);
  return 0;
}

// this fails because a (virtual) dealloc guess is not enumerated if an alloc is not present
int dead_alloca(int n)
{
  if (n > 0 && n <= 0) {
    int* p = (int*)alloca(n*sizeof(n));
    MYmyprintf("%p", p);
  }
  return 0;
}
