void foo(int*);
int ats(void)
{
  int ret;
  foo(&ret);
  return ret;
}
