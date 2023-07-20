int init(char* t, int i);

int vla_in_loop_conditional_exit(int n)
{
  int ret = 0;
  int i = 1;
  while (i < n) {
    char t[i];
    int r = init(t, i);
    if (r < 0)
      break;
    ret += t[i-1];
    ++i;
  }
  return ret;
}
