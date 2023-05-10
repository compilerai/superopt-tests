void nested_loop_peeling_depth_1(int **a, int n)
{
  for (int i = 0; i < n; i++) {
    a[i][0] = 0;
    a[i][1] = 0;
    a[i][2] = 0;
    for (int j = 3; j < 100; j++) {
      a[i][j] = i + j;
    }
  }
}

void nested_loop_peeling_depth_2(int ***a, int n, int m)
{
  for (int k = 0; k < m; k++) {
    for (int i = 0; i < n; i++) {
      a[k][i][0] = 0;
      a[k][i][1] = 0;
      a[k][i][2] = 0;
      for (int j = 3; j < 100; j++) {
        a[k][i][j] = i + j;
      }
    }
  }
}

/*
 * XXX eqtime increases exponentially for each loop depth
 */
/*
void nested_loop_peeling_depth_3(int ***a, int n, int m, int p)
{
  for (int l = 0; l < p; l++) {
    for (int k = 0; k < m; k++) {
      for (int i = 0; i < n; i++) {
        a[k][i][0] = 0;
        a[k][i][1] = 0;
        a[k][i][2] = 0;
        for (int j = 3; j < 100; j++) {
          a[k][i][j] = i + j;
        }
      }
    }
  }
}
*/
