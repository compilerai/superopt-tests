double near_zero()
{
  double f = 0.0000000000000000000000000000000000000000000000000000000000000000000001;

  return f*f*f*f*f;
}

double exceeds_range()
{
  double f = 10000000000000000000000000000000000000000000000000000000000000000000000.0;

  return f*f*f*f*f;
}

double invalid1(double a)
{
  if(a == 0.45)
    return (a*a + 3.1*a)/(a - 0.45);
  else
    return 0;
}

double invalid2(double a)
{
  return a/0; //inf for nonzero a
}

double invalid3()
{
  return 0.0/0; //-nan
}

