int vcu(int n, int k)
{
   int a[n];
   if (k > 0 && k <= n) {
      a[0] = 0;
      a[k-1] = 10;
      return a[0];
   }
   return 0;
}
