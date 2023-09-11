/* simple functions using floating-types without loops and calls */

typedef long double ldouble;

ldouble same(ldouble a)
{
  return a;
}

ldouble max(ldouble a, ldouble b)
{
  if(a >= b)
    return a;
  else
    return b;
}

ldouble sign(ldouble a)
{
  return -a;
}

ldouble abs1(ldouble a)
{
  if(a < 0)
    a = -a;

  return a;
}

ldouble abs_max(ldouble a, ldouble b)
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

ldouble add1(ldouble a)
{
  return a + 1;
}

ldouble sub1(ldouble a)
{
  return a - 1;
}

ldouble sqradd(ldouble a, ldouble b)
{
  ldouble s1 = a*a;
  ldouble s2 = b*b;
  ldouble r  = s1 + s2;

  return r;
}
