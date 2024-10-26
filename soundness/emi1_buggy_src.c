//Figure 1 from "Finding Compiler Bugs via Live Code Mutation"
//GCC 4.9, 5.1, and development trunk (6.0.0
//rev 223265) miscompile the variant at -O3.
//(https://gcc.gnu.org/bugzilla/show_bug.cgi?id=66186).
//The compiled binary throws segmentation fault instead
//of terminating normally.
//https://godbolt.org/z/8dofdnarc
//gcc 4.9.2 -O3 -m32

int a;

int emi1_buggy()
{
  int b = -1, d, e = 0, f[2] = { 0 };
  unsigned short c = b;

  for (; e < 3; e++)
    for (d = 0; d < 2; d++)
      /* a=0, b=-1, c=65535, d={0,1}, e={0,1,2}, f[0]=0 */
      if (a < 0) // Inserted code highlighted in gray.
        for (d = 0; d < 2; d++)
          if (f[c])
            break;
  return 0;
}
