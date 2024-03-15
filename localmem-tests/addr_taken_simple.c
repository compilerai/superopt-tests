void foo(int*);

int addr_taken_scalar(void)
{
  int ret;
  foo(&ret);
  return ret;
}

struct Point {
  int x; int y;
};

void read_points(struct Point* p1, struct Point* p2);

int addr_taken_structs(void)
{
  struct Point p1, p2;
  read_points(&p1, &p2);
  return p1.x - p2.x;
}
