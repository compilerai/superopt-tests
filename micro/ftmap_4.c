int g_x;

// R:
// W:
int* get_global_sym()
{
  return &g_x;
}

int ftmap_4_main()
{
  int* p = 0;
  g_x = 10;
  // p ~~> {}
  p = get_global_sym();
  // p ~~> GLOBALS
  *p = 20;
  return *p + g_x;
}
