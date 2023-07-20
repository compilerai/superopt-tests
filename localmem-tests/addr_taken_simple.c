void foo(int*);

int addr_taken_simple(void)
{
  int ret;
  foo(&ret);
  return ret;
}
