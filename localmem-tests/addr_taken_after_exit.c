void MYmybaz(int* p);
int addr_taken_after_exit(int p)
{
  if (p == 0) {
    return 0;
  }
  int x;
  MYmybaz(&x);
  return x + p;
}
