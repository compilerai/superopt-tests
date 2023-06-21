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

int s2233()
{

//	loop interchange
//	interchanging with one of two inner loops

		for (int i = 1; i < LEN2; i++) {
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j-1][i] + cc[j][i];
			}
			for (int j = 1; j < LEN2; j++) {
				bb[i][j] = bb[i-1][j] + cc[i][j];
			}
		}
	return 0;
}

