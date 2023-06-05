//#include "globals.h"

#define LEN 32000
#define LEN1 3200
#define LEN2 256

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


int s122(int n1, int n3)
{

//	induction variable recognition
//	variable lower and upper bound, and stride
//	reverse data access and jump in data access

	int j, k;
		j = 1;
		k = 0;
		for (int i = n1-1; i < LEN; i += n3) {
			k += j;
			a[i] += b[LEN - k];
		}
	return 0;
}

