#include <alloca.h>

// The eqproof of this function requires enumeration of a pathset without alloc edges.
// For the early exit path in dst, our full-pathset enumeration would
// enumerate pathset containing both the early exit path and the path through
// the loop, call the latter "second path".  The second path contains an alloc.
// Our alloc/dealloc correlation algorithm requires syntactic matching of
// alloc/dealloc in correlated pathsets. Because the early exit path of dst
// does not contain an alloc (required for correlating the alloc in second path),
// this correlation is rejected.
// We enumerate an additional pathset without the alloc that correlates successfully.
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

// the following function builds upon the previous function and
// adds an alloca() in the early exit path.
// This defeats our "enumerate additional pathset without alloc edges"
// strategy.
// Note that such a code is highly unlikely to appear in practice.
int unreachable_alloc_in_src_pathset_with_two_allocs(int n)
{
  if (n < 1) {
    int* a = alloca(sizeof(int));
    return (int)a;
  }
  int p[n];
  // compiler removes the (always true) initial condition check of this loop
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  return p[0];
}
