int foo(int*, int*, unsigned);

int v2il(unsigned n)
{
  int ret = 0;
  for (unsigned i = 1; i < n; ++i) {
   int v[4*i];
   int w[4*i];
   ret += foo(v,w,i);
  }
  return ret;
}
