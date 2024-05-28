unsigned no_cast(unsigned a[], unsigned b[])
{
  b[0] += a[0];

  return b[a[0]];
}

unsigned scalar_cast1u(float a)
{
  return (unsigned)a;
}

signed scalar_cast1s(float a)
{
  return (signed)a;
}

unsigned cast1u(float a[], float b[])
{
  b[0] += a[0];

  return (unsigned)a[0];
}

int cast1s(float a[], float b[])
{
  b[0] += a[0];

  return (int)a[0];
}

float cast1uf(float a[], float b[])
{
  b[0] += a[0];

  return (unsigned)a[0];
}

float cast1sf(float a[], float b[])
{
  b[0] += a[0];

  return (signed)a[0];
}

unsigned cast2uf(float a[], float b[])
{
  b[0] += a[0];

  return (unsigned)b[0];
}

unsigned cast2sf(float a[], float b[])
{
  b[0] += a[0];

  return (signed)b[0];
}

float cast3uf(float a[], float b[])
{
  b[0] += a[0];

  return b[(unsigned)a[0]];
}

float cast3sf(float a[], float b[])
{
  b[0] += a[0];

  return b[(signed)a[0]];
}
