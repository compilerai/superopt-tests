#include <alloca.h>

// This function triggers the unreachable alloc-dealloc in src path wfcond for
// a correctly constructed CG
// The wfcond has to be checked for the entry to exit correlation where the src
// pathset includes paths to both returns (due to being full-pathset), but the
// dst only includes the early exit path (because the loop anchor node lies in
// the way to the exit node and prohibits its enumeration)
int unreachable_alloc_in_src_pathset(int n)
{
  if (n < 1) {
    return 0;
  }
  int p[n];
  // compiler removes the (always true) initial condition check of this loop
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  return p[0];
}
