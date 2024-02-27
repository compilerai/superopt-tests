#include <inttypes.h>

int a[100][50];
int sum;
int nestedLoop(){
  sum = 0;
  for (int i =0; i < 100; i++) {
    for (int j = i ; j < 50; j++) {
      sum += a[i][j];
    }
  }
  return sum;
}
