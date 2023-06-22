#define LEN 32000
#define LEN1 3200
#define LEN2 2048

#define TYPE int
__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];

//loop unswitching, distributiona 1D loop
//Sum
//8 uf
int ex15_8()
{

//	control flow
//	if test using loop index
  int sum = 0;
	int mid = (LEN/2);
		for (int i = 0; i < mid; i++) {
				sum += c[a[i]];
    }
  #pragma GCC unroll 2
		for (int i = mid; i < LEN; i++) {
				sum += b[i];
		}
	return sum;
}
