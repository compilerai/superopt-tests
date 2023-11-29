/* arrays (also test for double) */

void array_add1(float a[])
{
  a[0] = a[0] + 1;
}

void array_addb(float a[], float b)
{
  a[0] = a[0] + b;
}

void array_rotate(float a[])
{
  float t = a[0];

  a[0] = a[1];
  a[1] = a[2];
  a[2] = t;
}

void array_set(float a[])
{
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
}

void array_copy(float a[], float b[])
{
  a[0] = b[0];
  a[1] = b[1];
  a[2] = b[2];
}

void array_max(float a[], float b[])
{
  if(b[0] > a[0])
    a[0] = b[0];

  if(b[1] > a[1])
    a[1] = b[1];

  if(b[2] > a[2])
    a[2] = b[2];
}

void array_addv(float a[], float b[], float c[])
{
  a[0] = b[0] + c[0];
  a[1] = b[1] + c[1];
  a[2] = b[2] + c[2];
}

void array_neg(float a[])
{
  a[0] = -a[0];
  a[1] = -a[1];
  a[2] = -a[2];
}

void array_mult(float a[])
{
  a[0] = a[0]*4;
}

