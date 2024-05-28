double near_zero_d()
{
  double f = 0.0000000000000000000000000000000000000000000000000000000000000000000001;

  return f*f*f*f*f;
}

double exceeds_range_d()
{
  double f = 10000000000000000000000000000000000000000000000000000000000000000000000.0;

  return f*f*f*f*f;
}

double invalid1_d(double a)
{
  if(a == 0.45)
    return (a*a + 3.1*a)/(a - 0.45);
  else
    return 0;
}

double invalid2_d(double a)
{
  return a/0; //inf for nonzero a
}

double invalid3_d()
{
  return 0.0/0; //-nan
}

