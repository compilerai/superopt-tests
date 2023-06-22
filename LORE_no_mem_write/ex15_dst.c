#define LEN 32000
#define LEN1 3200
#define LEN2 2048

#define TYPE int
__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];

//loop unswitching, distributiona 1D loop
//Sum
int ex15()
{

//	control flow
//	if test using loop index
  int sum = 0;
  int len = 16384;
	int mid = (len/2);
		for (int i = 0; i < mid; i++) {
				sum += b[2*i];
    }
		for (int i = mid; i < len; i++) {
				sum += c[i];
		}
	return sum;
}
