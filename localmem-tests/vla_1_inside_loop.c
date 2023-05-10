void MYmyDBG();
int MYmyfoo(int*,unsigned);

int vla_1_inside_loop(int *a, unsigned n)
{
  int ret = 0;
  for (unsigned i = 1; i < n; ++i) {
   MYmyDBG(); // XXX
   int v[4*i];
   ret += MYmyfoo(v,i);
  }
  return ret;
}
