int nested_loop_unrolling_depth_1(int **a, int n, int m)
{
  for (int i = 0; i<n; i++) {
    int j = 0;
    while (j < m) {
      a[i][j] = i;
      j++;
      if (j >= m)
        break;
      a[i][j] = i;
      j++;
      if (j >= m)
        break;
      a[i][j] = i;
      j++;
    }
  }
  return 0;
}

int nested_loop_unrolling_depth_2(int ***a, int n, int m, int p)
{
  for (int k = 0; k<p; k++) {
    for (int i = 0; i<n; i++) {
      int j = 0;
      while (j < m) {
        a[i][j][k] = i;
        j++;
        if (j >= m)
          break;
        a[i][j][k] = i;
        j++;
        if (j >= m)
          break;
        a[i][j][k] = i;
        j++;
      }
    }
  }
  return 0;
}

int nested_loop_unrolling_depth_3(int ****a, int n, int m, int p, int q)
{
  for (int l = 0; l<q; l++) {
    for (int k = 0; k<p; k++) {
      for (int i = 0; i<n; i++) {
        int j = 0;
        while (j < m) {
          a[i][j][k][l] = i;
          j++;
          if (j >= m)
            break;
          a[i][j][k][l] = i;
          j++;
          if (j >= m)
            break;
          a[i][j][k][l] = i;
          j++;
        }
      }
    }
  }
  return 0;
}

/*
 * XXX eqtime increases exponentially for each loop depth
 */
/*
int nested_loop_unrolling_depth_4(int *****a, int n, int m, int p, int q, int r)
{
  for (int t = 0; t<r; t++) {
    for (int l = 0; l<q; l++) {
      for (int k = 0; k<p; k++) {
        for (int i = 0; i<n; i++) {
          int j = 0;
          while (j < m) {
            a[i][j][k][l][t] = i;
            j++;
            if (j >= m)
              break;
            a[i][j][k][l][t] = i;
            j++;
            if (j >= m)
              break;
            a[i][j][k][l][t] = i;
            j++;
          }
        }
      }
    }
  }
  return 0;
}

int nested_loop_unrolling_depth_5(int ******a, int n, int m, int p, int q, int r, int s)
{
  for (int x = 0; x<s; x++) {
    for (int t = 0; t<r; t++) {
      for (int l = 0; l<q; l++) {
        for (int k = 0; k<p; k++) {
          for (int i = 0; i<n; i++) {
            int j = 0;
            while (j < m) {
              a[i][j][k][l][t][x] = i;
              j++;
              if (j >= m)
                break;
              a[i][j][k][l][t][x] = i;
              j++;
              if (j >= m)
                break;
              a[i][j][k][l][t][x] = i;
              j++;
            }
          }
        }
      }
    }
  }
  return 0;
}
*/
