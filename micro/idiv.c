int idiv(int a, int b)
{
  return a / b;
}

typedef struct St
{
  char c1;
  int i1;
} St;

St glb;

int idiv_rem10(int a, int b)
{
  if(a*a >= 10)
    glb.c1 = 'a';
  else if(a/b == 2)
    glb.c1 = 'b';
  else if(b*b >= 2)
    glb.c1 = 'c';
  else
    glb.c1 = 'd';

  glb.i1 = (a/b)%10;

  if(glb.c1 == 'a' || glb.c1 == 'd')
    glb.i1 = b*b*b;
  else if(glb.i1 == 9)
    glb.i1 = a/b;
  else
    glb.i1 = a*a*a;

  return glb.i1 + glb.c1;
}
