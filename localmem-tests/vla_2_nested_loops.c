int bar(int*);

int vla_2_nested_loops(int* a, unsigned n)
{
  if (n == 0)
    return 0;

  int v[n];
#pragma clang loop vectorize(disable) unroll(disable)
  for (unsigned i = 0; i < n-1; ++i) {
    unsigned vv[i+1];
    vv[0] = a[0];
#pragma clang loop vectorize(disable) unroll(disable)
    for (unsigned j = 1; j <= i; ++j) {
      vv[j] = a[j]+vv[j-1];
    }
    v[i] = vv[i];
  }
  return bar(v);
}

/*
int vla_2_nested_loops(int* a, unsigned n)
{
  if (n == 0)
    return 0;

  int v[n];
  int w[n];
#pragma clang loop vectorize(disable) unroll(disable)
  for (unsigned i = 0; i < n-1; ++i) {
    unsigned vv[i+1];
    vv[0] = a[0];
#pragma clang loop vectorize(disable) unroll(disable)
    for (unsigned j = 1; j <= i; ++j) {
      if (a[j] < 0)
        goto end;
      vv[j] = a[j]+vv[j-1];
    }
    v[i] = vv[i];
    w[i] = a[i];
  }
  return bar(v,w);
end:
  return 0;
}
*/
