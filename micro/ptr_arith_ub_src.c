void
ptr_arith_ub(int* src, int n, int* dst)
{
  if (n < 0)
    return;
  for (int i = 0; i < n; ++i) {
    dst[i] = src[i] + 42;
  }
}
