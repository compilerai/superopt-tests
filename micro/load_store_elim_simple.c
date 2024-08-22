/* load/store elimination test cases
 * ---------------------------------
 * In each testcase the compiler (clang/LLVM -O2) is able to eliminate a load
 * or store which was previously accessed (loaded from or stored to).
 * What is significant is that it happens across loops or from eqchecker
 * persective, across anchor nodes.
 * Thus to prove equivalence in such a scenario the invariant inference
 * algorithm must maintain invariants relating memory accesses and scalars.
 * In particular for patterns:
 *  L: x <- load p   <|>   store p, x
 *     .....
 *     .....
 *  R: y <- load p'  <|>   store p', x
 * The compiler optimize away the store or replace the load with a scalar move:
 *  R: y <- x        <|>   // "store p', x" removed
 * Note that p' need not be syntactically equivalent to p (as is the case in below benchmarks)
 * The optimization will trigger if a CSE or GVN pass is able to establish that p == p'.
 */

int load_load_elim(int *P, int C, int D) {
  int x = *P;
  int acc = 0;
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C+D; ++i) {
    acc += (i&3);
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C-D; ++i) {
    acc += (i^3);
  }
  return acc+x+*P;
}

int load_store_elim(int *P, int C, int D) {
  int x = *P;
  int acc = 0;
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C+D; ++i) {
    acc += (i&3);
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C-D; ++i) {
    acc += (i^3);
  }
  *P = x;
  return acc+x;
}

int store_load_elim(int *P, int C, int D) {
  *P = C+D;
  int acc = 0;
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C+D; ++i) {
    acc += (i&3);
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C-D; ++i) {
    acc += (i^3);
  }
  return *P + acc;
}

// in store_store_elim, clang/LLVM sinks the store to the last occurrence as (*P) is not used anywhere
// because we require equality of memories at each anchor node, eqcheck fails in this case
int store_store_elim(int *P, int C, int D) {
  *P = C+D; // eliminated by clang/LLVM
  int acc = 0;
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C+D; ++i) {
    acc += (i&3);
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < C-D; ++i) {
    acc += (i^3);
  }
  *P = C+D; // only this one is preserved
  return acc;
}
