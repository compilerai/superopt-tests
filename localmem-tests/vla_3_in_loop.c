int foo(int*, int*, int*, unsigned);

int vla_3_in_loop(int *a, unsigned n)
{
  int ret = 0;
#pragma clang loop vectorize(disable) unroll(disable)
  for (unsigned i = 1; i < n; ++i) {
    int v[4*i];
    int w[4*i];
    int x[4*i];
    ret += foo(v,w,x,i);
  }
  return ret;
}
