extern void printa(int*,int);

unsigned fib(int n, int m)
{
  int v[n+2];
  v[0] = 0;
  v[1] = 1;
  for (int i = 2; i <= m; ++i) {
    v[i] = v[i-1]+v[i-2];
  }
  printa(v, m);
  return v[m];
}
