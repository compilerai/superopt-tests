#include <stdio.h>
#include <string.h>

int addr_taken_parameter_scalar(int a)
{
  char x;
  if (a == 0) {
    scanf("%c %d", &x, &a);
  } else {
    scanf("%c", &x);
  }
  return x+a;
}

struct Point {
  int x; int y;
};

int addr_taken_parameter_small_struct(struct Point p1, struct Point p2)
{
  char x;
  if (p1.x == 0 || p2.x == 0) {
    scanf("%c %d %d", &x, &p1.x, &p2.x);
  } else {
    scanf("%c", &x);
  }
  return x+(p1.x+p1.y)+(p2.x+p2.y);
}

struct Str {
  short is_small;
  char buf[80];
  char *ptr;
};


int addr_taken_parameter_large_struct(struct Str s)
{
  scanf("%hd", &s.is_small);
  char* p = s.is_small ? s.buf : s.ptr;
  scanf("%s",p);
  return strlen(p);
}
