#define LEN 32000
#define LEN1 3200
#define LEN2 2048

#define TYPE int
__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];

// 1D-MW
// loop peeling
int ex109()
{

  b[0] = 0;
  b[1] = 0;
  b[2] = 0;
	for (int j = 3; j < LEN ; j++) {
		  b[j] = a[j];
	}
	return 0;
}
