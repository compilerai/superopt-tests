int vla_in_loop_conditional_continue(int n)
{
  int ret = 0;
  int i = 1;
  while (i < n) {
    char t[i];
    int r = MYmyInit(t, i);
    if (r < 0)
      continue;
    ret += t[i-1];
    ++i;
  }
  return ret;
}
