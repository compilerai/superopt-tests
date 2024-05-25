/* simple functions using floating-types without loops and calls */

double max_d(double a, double b)
{
  if(a >= b)
    return a;
  else
    return b;
}

double sign_d(double a)
{
  return -a;
}

double abs1_d(double a)
{
  if(a < 0)
    a = -a;

  return a;
}

double abs_max_d(double a, double b)
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

double add1_d(double a)
{
  return a + 1;
}

double sub1_d(double a)
{
  return a - 1;
}

double sqradd_d(double a, double b)
{
  double s1 = a*a;
  double s2 = b*b;
  double r  = s1 + s2;

  return r;
}
