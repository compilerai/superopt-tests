int x;
int y;

// R: M[arg.0]
// W: M[arg.0]
void w_arg(int* p)
{
  *p *= 10;
}

// R: M[arg.0], M[sym.y]
// W: M[sym.x]
int w_g_x(int* p)
{
  x = *p+y;
  return *p+10;
}

int ftmap_1_main()
{
  w_arg(&x);        // R: x,  W: x
  return w_g_x(&x); // R: x,y W: x
}

int main(int n, char* argv[])
{
  return ftmap_1_main();
}
