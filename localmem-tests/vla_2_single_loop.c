int vla_2_single_loop(int *a, unsigned n)
{
  if (n == 0)
    return 0;

  int v[n];
  int w[n];
  for (unsigned i = 0; i < n; ++i) {
    MYmyDBG();
    v[i] = a[i]*a[i];
    w[i] = a[i]+a[i];
  }
  return MYmybar(v,w);
}
