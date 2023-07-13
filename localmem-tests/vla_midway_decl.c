int foo(int*);

// local declaration not in prologue
int vla_midway_decl(int* a, unsigned n, int* b)
{
  if (n == 0)
    return 0;

  b[0] = a[0];
#pragma clang loop vectorize(disable) unroll(disable)
  for (unsigned i = 1; i < n; ++i) {
    b[i] = b[i-1] + a[i];
  }
  int v[n];
#pragma clang loop vectorize(disable) unroll(disable)
  for (unsigned i = 0; i < n; ++i) {
    v[i] = a[i]*b[i];
  }
  return foo(v);
}
