int init(char* t, int i);

int vilcc(int n)
{
  int ret = 0;
  int i = 1;
  while (i < n) {
    char t[i];
    if (init(t, i) < 0)
      continue;
    ret += t[i-1];
    ++i;
  }
  return ret;
}