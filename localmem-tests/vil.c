void MYmyscanf(char* fmt, ...);
int vil(int n)
{
  int ret = 0;
  for (int i = 1; i < n; ++i) {
    char t[i];
    MYmyscanf("%s",t);
    ret += t[i-1];
  }
  return ret;
}
