#define SIZE 16000
unsigned f[SIZE];

// GCC -O3 register allocates both f[i-1] and f[i-2]
// Clang -O3 register allocates only f[i-1]
// Requires hoisting-exprs or anticipated-mem-accesses to collect the hoisted select()
unsigned loop_hoisting(unsigned n)
{
  f[0] = 0;
  f[1] = 1;
#pragma clang loop unroll(disable) vectorize(disable)
  for (unsigned i = 2; i <= n; ++i) {
    f[i] = f[i-1]+f[i-2];
  }
  return f[n];
}
