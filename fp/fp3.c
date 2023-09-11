typedef struct St
{
  char c1;
  int i1;
  float f1;
  double d1;
} St;

static St glb;

//all 4 cases timeout: swapping operands in two fadd (align according to their correspondence)
//make the expr pass
double arrays1(float a[], double b[])
{
  return a[0] + a[1] + b[0] + b[1];
}

//check after arrays1 works
/*double arrays2(float a[], double b[])
{
  return a[0] + a[1] + a[2] + b[0] + b[1] + b[2];
}*/

double variance(float a0, float a1, float a2, double *o1)
{
  double avg = (a0 + a1 + a2)/(double)3;
  double var;
 
  var =  (a0 - avg)*(a0 - avg);
  var += (a1 - avg)*(a1 - avg);
  var += (a2 - avg)*(a2 - avg);
  var = var/3;

  *o1 = avg;

  return var;
}

float comp1(float a, double b)
{
  if(a*a >= 10.4)
    glb.c1 = 'a';
  else if(a/b == 2)
    glb.c1 = 'b';
  else if(b*b >= 2.5)
    glb.c1 = 'c';
  else
    glb.c1 = 'd';

  glb.i1 = ((int)(a/b))%10;

  glb.f1 = (a == b ? 0 : glb.i1) + (a/b)/10;

  if(glb.c1 == 'a' || glb.c1 == 'd')
    glb.d1 = b*b*b;
  else if(glb.i1 == 9)
    glb.d1 = a/b;
  else
    glb.d1 = a*a*a;

  return glb.f1 + glb.d1;
}

void outptr1(float *a, double *b)
{
  a[0] = 1.50;
  a[1] = 1.51;

  b[0] = 2.50;
  b[1] = 2.51;
}

float mixtype1(float a, double b, char c, short d, int e)
{
  a = a*c + d;
  b = b/c + d;

  return a*b - e;
}

