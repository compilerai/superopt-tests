#define STEP do {            \
    *x = (*a)&(*b);          \
    *y = ~(*a)&(*c);         \
    *z = (*x)^(*y);          \
    *c = (*x)/(*y);          \
    *d = (*z)*(*c);          \
    *a = (*c)/2;             \
    *b = (*d)/2;             \
  } while (0)

int non_linear_comp_2_steps(int* a, int* b, int* c, int* d, int* x, int* y, int* z)
{
  STEP; STEP;
  return *x**y**z**c**d;
}

// anything more than 2 steps chokes our preprocessing stage (pointsto and other analyses)
// the following will timeout
int non_linear_comp_5_steps(int* a, int* b, int* c, int* d, int* x, int* y, int* z)
{
  STEP; STEP; STEP; STEP; STEP;
  return *x**y**z**c**d;
}
