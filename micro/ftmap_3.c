int* g_p;

// R: arg.0, M[arg.0]
// W: M[arg.0]
void w_deref_deref_arg(int **p)
{
  **p = 10;
}

void nop(int **p)
{
  ;
}

int ftmap_3_main()
{
  int l = 11;
  int* l_p = &l;
  g_p = &l;                 // l escaped into globals

  nop(&l_p);                // R:        W:
  w_deref_deref_arg(&l_p);  // R: l_p,l  W: l

  return 0;
}
