int quadruple_lt(double a[], double b[])
{
  return (a[0] < b[0]) && (a[1] < b[1]) && (a[2] < b[2]) && (a[3] < b[3]);
}

double diff1(double a, double b)
{
  double d;

  d = a - b;

  if(d < 0)
    d = -d;

  return d;
}

double diff1a(double a[], double b[])
{
  double d1;

  d1 = a[0] - b[0];

  if(d1 < 0)
    d1 = -d1;

  return d1;
}

double diff2(double a[], double b[])
{
  double d1, d2;

  d1 = a[0] - b[0];
  d2 = a[1] - b[1];

  if(d1 < 0)
    d1 = -d1;

  if(d2 < 0)
    d2 = -d2;

  return d1 + d2;
}

#define SWAP(i, j)     \
{                      \
  if(a[i] > a[j])      \
  {                    \
    t = a[i];          \
    a[i] = a[j];       \
    a[j] = t;          \
  }                    \
}

void sort2(double a[])
{
  double t;

  SWAP(0, 1)
}

/*void sort3(double a[])
{
  double t;

  SWAP(0, 1)
  SWAP(1, 2)
  SWAP(0, 1)
}
*/
