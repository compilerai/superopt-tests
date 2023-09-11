/* simple functions using floating-types without loops and calls */

double max(double a, double b)
{
  if(a >= b)
    return a;
  else
    return b;
}

double sign(double a)
{
  return -a;
}

double abs1(double a)
{
  if(a < 0)
    a = -a;

  return a;
}

double abs_max(double a, double b)
{
  if(a < 0)
    a = -a;

  if(b < 0)
    b = -b;

  if(a >= b)
    return a;
  else
    return b;
}

double add1(double a)
{
  return a + 1;
}

double sub1(double a)
{
  return a - 1;
}

double sqradd(double a, double b)
{
  double s1 = a*a;
  double s2 = b*b;
  double r  = s1 + s2;

  return r;
}
