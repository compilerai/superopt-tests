//Figure 9f from "Finding Compiler Bugs via Live Code Mutation"
//GCC 4.9.2, 5.1, and development
//trunk (6.0.0 rev 223630) miscompiles
//the variant at -O3. The compiled binary
//aborts instead of terminating normally.
//https://gcc.gnu.org/bugzilla/show_bug.cgi?id=66272
//https://godbolt.org/z/377ce8Pv1
//gcc 4.9.2 -O3 -m32

void MYmyassert(int b);

struct S {
  int f0;
  int f1;
};
int b;
int emi9f_buggy()
{
  struct S a[2] = { 0 };
  struct S d = { 0, 1 };
  for (b = 0; b < 2; b++) {
    a[b] = d;
    d = a[0];
  }
  return d.f1 != 1;
}
