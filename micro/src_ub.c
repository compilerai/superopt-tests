int src_always_ub(int x)
{
  int y = 0;
  y = x/y;
  return y;
}

int src_cond_ub(int x)
{
  int y = 0;
  if (x != 0) {
    y = x/y;
  }
  return y;
}
