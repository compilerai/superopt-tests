double add_const_d(double a)
{
  return a + 3.14159;
}

double mult_const_d(double a)
{
  return a * 3.14159;
}

int cmp_const_d(double a)
{
  return a == 3.14159 || 2*a > 1.41;
}

double expr1_d()
{
  return 1.0/3;
}

double expr2_d(double a)
{
  double b = 0.12345;

  return a/b + (a*a)/(b*b) + (a*a*a)/(b*b*b);
}

double expr3_d(double a)
{
  return (3.1*a*a + 2.5*a + 7.9) / (0.9*a*a + 6.5*a + 8.4);
}

double expr3_1_d(double a)
{
  return (3.1*a*a + 7.9) / (0.9*a*a + 8.4);
}

double const_expr_d()
{
  double f = 0.316438636889084;

  return f + f*f + 1/f + 1/(f*f);
}
