void MYmyfoo(int*);
void MYmybar(int*,int);

int local_used_in_unreachable_loop(void)
{
  int ret = 0;
  while (ret) {
    MYmyfoo(&ret);
  }
  return ret;
}

int local_used_in_unreachable_loop_vla(void)
{
  int ret = 0;
  while (ret) {
    int v[ret+1];
    MYmybar(v, ret+1);
  }
  return ret;
}
