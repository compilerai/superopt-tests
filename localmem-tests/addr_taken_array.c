void bar(char*);
int MYmystrtol(char* ret, int, int);
int addr_taken_array()
{
  char ret[8];
  bar(ret);
  return MYmystrtol(ret, 0, 16);
}
