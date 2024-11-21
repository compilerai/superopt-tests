// on the exit path, d2s subs arr[n-1] with i*i
// the ret-regs query becomes (sel()*sel() == i*i*sel())
// and solver times out on this
// without d2s, this passes
int non_linear_comp(int* arr, int n)
{
  if (n < 1) {
    return 0;
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i < n; ++i) {
    arr[i] = i*i;
  }
  return arr[0]*arr[n-1];
}
