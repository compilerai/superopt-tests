#define LEN 32000
#define LEN1 3200
#define LEN2 2048

#define TYPE int
__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];

// 1D-MW
// loop peeling
// 8 uf
int ex109_8()
{

	for (int j = 0; j < LEN ; j++) {
    if(j < 3)
      a[j] = 100;
    else 
		  a[j] = b[j]+2;
	}
	return 0;
}
