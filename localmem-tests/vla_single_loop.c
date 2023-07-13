int vla_single_loop(unsigned n)
{
  if (n == 0)
    return 0;

  int v[n];
#pragma clang loop vectorize(disable) unroll(disable)
  for (unsigned i = 0; i < n; ++i) {
    v[i] = i*(i+1);
  }
  return v[0]+v[n-1];
}
