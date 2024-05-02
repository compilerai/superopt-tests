struct foo {
	int a;
	int b;
};
 
struct foo ret_struct(int n, int m)
{
	struct foo t = {n, m};
	return t;
}
 
int call_ret_struct(int n, int m)
{
	struct foo t1 = ret_struct(n, m);
	return t1.a;
}
