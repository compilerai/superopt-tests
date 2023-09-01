
void baz(int* p);
int addr_taken_conditional(int* p)
{
  int x;
  if (!p) p = &x;
  baz(p);
  return *p;
}
