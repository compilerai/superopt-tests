int g_x;

// R:
// W: { g_x }
// ret: g_x
int* mut_g_x()
{
  g_x += 10;
  return &g_x;
}

int ftmap_5_main()
{
  int* p = 0;
  g_x = 10;
  // p ~~> {}
  p = mut_g_x();
  // p ~~> GLOBALS (conservative) -- our result
  // p ~~> g_x (precise) -- compiler's result
  *p += 20; // compiler writes to g_x directly instead of chasing pointer
  return *p + g_x; // reads g_x directly
}
