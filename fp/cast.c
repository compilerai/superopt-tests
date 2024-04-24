unsigned no_cast(unsigned a[], unsigned b[])
{
  b[0] += a[0];

  return b[a[0]];
}

float cast1(float a[], float b[])
{
  b[0] += a[0];

  return (unsigned)a[0];
}

unsigned cast2(float a[], float b[])
{
  b[0] += a[0];

  return (unsigned)b[0];
}

float cast3(float a[], float b[])
{
  b[0] += a[0];

  return b[(unsigned)a[0]];
}
