void foo(char*);
int bar(char* ret, int, int);
int ata()
{
  char ret[8];
  foo(ret);
  return bar(ret, 0, 16);
}
