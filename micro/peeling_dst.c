int peeling(int n)
{
  if(n < 2)
    return 0;

  int i = 0;
  i++;
  i++;
  while(i < n)
  {
    i++;
  }
  return i;
}


int main()
{
  return 0;
}
