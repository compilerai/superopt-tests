#define LEN 32000
#define LEN1 3200
#define LEN2 2048

#define TYPE int
__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];

//loop unroll complete 1D
//Sum
int ex16()
{

  int sum1 = 0;
	for (int j = 0; j < 3; j++) 
	  sum1 += a[j];
	for (int j = 3; j < LEN; j++) 
	  sum1 += b[j];
	return sum1;
}
