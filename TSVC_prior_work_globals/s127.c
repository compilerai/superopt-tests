#define LEN 4000
#define LEN1 3200
#define LEN2 128

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/param.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

#define TYPE int

#define lll LEN

extern TYPE val;
extern __attribute__ ((aligned(16))) TYPE X[lll],Y[lll],Z[lll],U[lll],V[lll];

extern TYPE array[LEN2*LEN2] __attribute__((aligned(16)));

extern TYPE x[LEN] __attribute__((aligned(16)));
extern TYPE temp, s;

extern __attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];


extern TYPE indx[LEN] __attribute__((aligned(16)));


extern TYPE* /*__restrict__*/ xx;
extern TYPE* yy;
extern TYPE arr[LEN];
extern int val_s;

extern void init_local1(TYPE *val1);
extern void init_local2(TYPE *val1, TYPE *val2);
extern void init_local3(TYPE *val1, TYPE *val2, TYPE *val3);
extern void init_local4(TYPE *val1, TYPE *val2, TYPE *val3, TYPE *val4);
extern void init_local5(TYPE *val1, TYPE *val2, TYPE *val3, TYPE *val4, TYPE *val5);

extern void print_local1(TYPE *val1);
extern void print_local2(TYPE *val1, TYPE *val2);
extern void print_local3(TYPE *val1, TYPE *val2, TYPE *val3);
extern void print_local4(TYPE *val1, TYPE *val2, TYPE *val3, TYPE *val4);
extern void print_local5(TYPE *val1, TYPE *val2, TYPE *val3, TYPE *val4, TYPE *val5);

  extern TYPE a[LEN];
int s127()
{

//	induction variable recognition
//	induction variable with multiple increments

  
	int j;
		j = -1;
		for (int i = 0; i < LEN/2; i++) {
			j++;
			a[j] = b[i] + c[i] * d[i];
			j++;
			a[j] = b[i] + c[i] * e[i];
		}
  print_local1(a);
	return 0;
}
