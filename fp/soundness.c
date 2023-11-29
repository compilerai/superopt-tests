//taken from https://gcc.gnu.org/bugzilla/show_bug.cgi?id=323
const double test(double x, double y)
{
  const double y2 = x + 1.0;
  //if (y != y2) printf("error\n");
  return y2;
}

//void main()
//{
//  const double x = .012;
//  const double y = x + 1.0;
//
//  const double y2 = test(x, y);
//  if (y != y2) printf("error\n");
//}
