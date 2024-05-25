/* simple functions using floating-types without loops and calls */

typedef long double ldouble;

ldouble same_ld(ldouble a)
{
  return a;
}

ldouble max_ld(ldouble a, ldouble b)
{
  if(a >= b)
    return a;
  else
    return b;
}

ldouble sign_ld(ldouble a)
{
  return -a;
}

ldouble abs1_ld(ldouble a)
{
  if(a < 0)
    a = -a;

  return a;
}

ldouble abs_max_ld(ldouble a, ldouble b)
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

ldouble add1_ld(ldouble a)
{
  return a + 1;
}

ldouble sub1_ld(ldouble a)
{
  return a - 1;
}

ldouble sqradd_ld(ldouble a, ldouble b)
{
  ldouble s1 = a*a;
  ldouble s2 = b*b;
  ldouble r  = s1 + s2;

  return r;
}
