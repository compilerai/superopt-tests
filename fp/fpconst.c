//also test the variant with type "double"

float add_const(float a)
{
  return a + 3.14159;
}

float mult_const(float a)
{
  return a * 3.14159;
}

int cmp_const(float a)
{
  return a == 3.14159 || 2*a > 1.41;
}

// XXX DELETE ME AFTER DEBUGGING
int cmp_consti(int a)
{
  return a == 3 || 2*a > 1;
}

float expr1()
{
  return 1.0/3;
}

float expr2(float a)
{
  float b = 0.12345;

  return a/b + (a*a)/(b*b) + (a*a*a)/(b*b*b);
}

float expr3(float a)
{
  return (3.1*a*a + 2.5*a + 7.9) / (0.9*a*a + 6.5*a + 8.4);
}

float expr3_1(float a)
{
  return (3.1*a*a + 7.9) / (0.9*a*a + 8.4);
}

float const_expr()
{
  float f = 0.316438636889084;

  return f + f*f + 1/f + 1/(f*f);
}

