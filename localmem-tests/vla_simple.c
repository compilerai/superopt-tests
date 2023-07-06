void foo(int*);
void bar(int*);
void baz(int*);

void vla_simple(int n, int m)
{
  int v[n];
  foo(v);
}

void vla_simple_nested_1(int n, int m)
{
  int v1[n];
  {
    int v2[m];
    foo(v2);
  }
  bar(v1);
}

void vla_simple_nested_2(int n, int m, int o)
{
  int v1[n];
  {
    int v2[m];
    {
      int v3[o];
      foo(v3);
    }
    bar(v2);
  }
  baz(v1);
}
