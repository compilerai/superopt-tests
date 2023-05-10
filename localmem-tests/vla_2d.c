#define MAX(x, y) ((x > y) ? (x) : (y))

int vla_2d(const char *s, const char *t, int m, int n)
{
  int dp[m+1][n+1];

#pragma clang loop vectorize(disable) unroll(disable)
  for (int i = 0; i <= m; ++i) {
    MYmyDBG(); // XXX
    dp[i][0] = 0;
  }
#pragma clang loop vectorize(disable) unroll(disable)
  for (int j = 0; j <= n; ++j) {
    MYmyDBG(); // XXX
    dp[0][j] = 0;
  }

  for (int i = 1; i <= m; i++) {
    MYmyDBG(); // XXX
    for (int j = 1; j <= n; j++) {
      MYmyDBG(); // XXX
      if (s[i-1] == t[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}
