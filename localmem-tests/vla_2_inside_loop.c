void MYmyDBG();
int MYmyfoo(int*, int*, unsigned);

int vla_2_inside_loop(int *a, unsigned n)
{
  int ret = 0;
  for (unsigned i = 1; i < n; ++i) {
   MYmyDBG(); // XXX
   int v[4*i];
   int w[4*i];
   ret += MYmyfoo(v,w,i);
  }
  return ret;
}
