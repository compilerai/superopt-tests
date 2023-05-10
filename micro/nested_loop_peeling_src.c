void nested_loop_peeling_depth_1(int **a, int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 100; j++) {
      if (j < 3)
        a[i][j] = 0;
      else
        a[i][j] = i + j;
    }
  }
}

void nested_loop_peeling_depth_2(int ***a, int n, int m)
{
  for (int k = 0; k < m; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 100; j++) {
        if (j < 3)
          a[k][i][j] = 0;
        else
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
        for (int j = 0; j < 100; j++) {
          if (j < 3)
            a[k][i][j] = 0;
          else
            a[k][i][j] = i + j;
        }
      }
    }
  }
}
*/
