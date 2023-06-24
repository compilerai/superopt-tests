int nested_loops_depth_1(int **a, int n)
{
  #pragma clang loop unroll(disable) vectorize(disable)
  for (int i = 0; i<n; i++) {
  #pragma clang loop unroll(disable) vectorize(disable)
    for (int j = 0; j<n; j++) {
        a[i][j] = i+j;
    }
  }
  return 0;
}

int nested_loops_depth_2(int ***a, int n)
{
  #pragma clang loop unroll(disable) vectorize(disable)
  for (int i = 0; i<n; i++) {
  #pragma clang loop unroll(disable) vectorize(disable)
    for (int j = 0; j<n; j++) {
  #pragma clang loop unroll(disable) vectorize(disable)
      for (int k = 0; k<n; k++) {
        a[i][j][k] = i+j+k;
      }
    }
  }
  return 0;
}

int nested_loops_depth_3(int ****a, int n)
{
  #pragma clang loop unroll(disable) vectorize(disable)
  for (int i = 0; i<n; i++) {
#pragma clang loop unroll(disable) vectorize(disable)
    for (int j = 0; j<n; j++) {
#pragma clang loop unroll(disable) vectorize(disable)
      for (int k = 0; k<n; k++) {
#pragma clang loop unroll(disable) vectorize(disable)
        for (int l = 0; l<n; l++) {
          a[i][j][k][l] = i+j+k+l;
        }
      }
    }
  }
  return 0;
}

int nested_loops_depth_4(int *****a, int n)
{
#pragma clang loop unroll(disable) vectorize(disable)
for (int i = 0; i<n; i++) {
#pragma clang loop unroll(disable) vectorize(disable)
  for (int j = 0; j<n; j++) {
#pragma clang loop unroll(disable) vectorize(disable)
    for (int k = 0; k<n; k++) {
#pragma clang loop unroll(disable) vectorize(disable)
      for (int l = 0; l<n; l++) {
#pragma clang loop unroll(disable) vectorize(disable)
        for (int t = 0; t<n; t++) {
          a[i][j][k][l][t] = i+j+k+l+t;
        }
      }
    }
  }
}
  return 0;
}

int nested_loops_depth_5(int ******a, int n)
{
#pragma clang loop unroll(disable) vectorize(disable)
for (int i = 0; i<n; i++) {
#pragma clang loop unroll(disable) vectorize(disable)
  for (int j = 0; j<n; j++) {
#pragma clang loop unroll(disable) vectorize(disable)
    for (int k = 0; k<n; k++) {
#pragma clang loop unroll(disable) vectorize(disable)
      for (int l = 0; l<n; l++) {
#pragma clang loop unroll(disable) vectorize(disable)
        for (int t = 0; t<n; t++) {
#pragma clang loop unroll(disable) vectorize(disable)
          for (int x = 0; x<n; x++) {
              a[i][j][k][l][t][x] = i+j+k+l+t+x;
            }
          }
        }
      }
    }
  }
  return 0;
}

int nested_loops_depth_6(int *******a, int n)
{
#pragma clang loop unroll(disable) vectorize(disable)
  for (int i = 0; i<n; i++) {
#pragma clang loop unroll(disable) vectorize(disable)
    for (int j = 0; j<n; j++) {
#pragma clang loop unroll(disable) vectorize(disable)
      for (int k = 0; k<n; k++) {
#pragma clang loop unroll(disable) vectorize(disable)
        for (int l = 0; l<n; l++) {
#pragma clang loop unroll(disable) vectorize(disable)
          for (int t = 0; t<n; t++) {
#pragma clang loop unroll(disable) vectorize(disable)
            for (int x = 0; x<n; x++) {
#pragma clang loop unroll(disable) vectorize(disable)
              for (int y = 0; y<n; y++) {
                a[i][j][k][l][t][x][y] = i+j+k+l+t+x+y;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
