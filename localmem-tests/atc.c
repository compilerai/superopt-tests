void foo(int* p);
int atc(int* p)
{
  int x;
  if (!p) p = &x;
  foo(p);
  return *p;
}
