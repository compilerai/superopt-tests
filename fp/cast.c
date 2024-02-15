unsigned no_cast(unsigned a[], unsigned b[])
{
  b[0] += a[0];

  return b[a[0]];
}

float cast_f(float a[], float b[])
{
  b[0] += a[0];

  return b[(unsigned)a[0]];
}
