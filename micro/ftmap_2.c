struct ptr_pair
{
  int* p1;
  int* p2;
};

int x;
int y;

// R: arg.0
// W: M[arg.0]
void w_deref_deref_arg(struct ptr_pair* pp)
{
  *(pp->p1) = 10;
}

// R:
// W: arg.0
void w_deref_arg(struct ptr_pair* pp)
{
  pp->p2 = &x;
}

int ftmap_2_main(int n, char* a[])
{
  int l;
  struct ptr_pair pp = { .p1 = &l, .p2 = &y };
  // M[&pp] ~~> { &y, &l }

  w_deref_deref_arg(&pp); // R: pp,y,l W: pp,y,l
  // M[&pp] ~~> { &y, &l }

  w_deref_arg(&pp);       // R:        W: pp
  // M[&pp] ~~> { &y, &x-heap, &l }

  return 0;
}

int main(int n, char* argv[])
{
  return ftmap_2_main(n, argv);
}
