#define LEN 32000
#define LEN1 3200
#define LEN2 2048

#define TYPE int
__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];

//loop unroll complete 1D
//MW
int ex1011()
{

  int sum1 = 0;
	for (int j = 0; j < 3; j++) 
	  c[j] += a[j];
	for (int j = 3; j < LEN; j++) 
	  c[j] += b[j];
	return 0;
}

