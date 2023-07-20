void foo(int*);
void bar(int*,int);

int local_used_in_unreachable_loop(void)
{
  int ret = 0;
  while (ret) {
    foo(&ret);
  }
  return ret;
}

int local_used_in_unreachable_loop_vla(void)
{
  int ret = 0;
  while (ret) {
    int v[ret+1];
    bar(v, ret+1);
  }
  return ret;
}
