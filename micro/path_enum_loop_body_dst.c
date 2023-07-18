int foo(int);

// requires u=2 if inner loop-body PC is NOT enumerated as waypost node in src
void path_enum_loop_body_nested(int* a, unsigned n)
{
  if (n == 0)
    return;

  if (0 < n-1) {
    unsigned i = 0;
    do {
      int acc = a[0];
      if (1 <= i) {
        unsigned j = 1;
        do {
          if (a[j] < 0)
            break;
          acc += a[j];
        } while (++j <= i);
      }
      foo(acc);
    } while (++i < n-1);
  }
  return;
}
