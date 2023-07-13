void MYmyDBG();
int MYmybar(int*,int*,int*,int*);

int vla_4_single_loop(int *a, unsigned n)
{
  if (n == 0)
    return 0;

  int v[n];
  int w[n];
  int x[n];
  int y[n];
#pragma clang loop vectorize(disable) unroll(disable)
  for (unsigned i = 0; i < n; ++i) {
    v[i] = a[i]*a[i];
    w[i] = a[i]+a[i];
    x[i] = a[i]^a[i];
    y[i] = a[i]-x[i];
  }
  return MYmybar(v,w,x,y);
}
