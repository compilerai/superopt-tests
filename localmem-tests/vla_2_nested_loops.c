int vla_2_nested_loops(int* a, unsigned n)
{
  if (n == 0)
    return 0;

  int v[n];
  int w[n];
  for (unsigned i = 0; i < n-1; ++i) {
    MYmyDBG(); // XXX
    unsigned vv[i+1];
    vv[0] = a[0];
    for (unsigned j = 1; j <= i; ++j) {
      MYmyDBG(); // XXX
      if (a[j] < 0)
        goto end;
      vv[j] = a[j]+vv[j-1];
    }
    v[i] = vv[i];
    w[i] = a[i]*a[i];
  }
  return MYmybar(v,w);
end:
  return 0;
}
