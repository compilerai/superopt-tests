#include <inttypes.h>

#define LEN 1024
int a[LEN];
int b[LEN];
int c[LEN];
int d[LEN];

// non-logical if's
// arithmetic if
int s441()
{
  for (int i = 0; i < LEN; i++) {
    if (d[i] < 0) {
      a[i] += b[i] * c[i];
    } else if (d[i] == 0) {
      a[i] += b[i] * b[i];
    } else {
      a[i] += c[i] * c[i];
    }   
  }   
  return 0;
}
