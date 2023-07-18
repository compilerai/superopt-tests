int foo(int);

void path_enum_loop_body_nested(int* a, unsigned n)
{
  if (n == 0)
    return;

  for (unsigned i = 0; i < n-1; ++i) {
    int acc = a[0];
    for (unsigned j = 1; j <= i; ++j) {
      if (a[j] < 0)
        break; // does not work if `break` is replaced with `goto`
      acc += a[j];
    }
    foo(acc);
  }
  return;
}
