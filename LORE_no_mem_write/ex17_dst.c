#define LEN 32000
#define LEN1 3200
#define LEN2 2048

#define TYPE int
__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];


//remainder loop  fusion
//Sum
int ex17(int n)
{

  int sum1 = 0;
  int sum2 = 0;
  if( n < 4)
  {
    if(n >= 1) {  sum1 += a[0]; sum2 += b[0];}
    if(n >= 2) {  sum1 += a[1]; sum2 += b[1];}
    if(n == 3) {  sum1 += a[2]; sum2 += b[2];}
  }
  else
  {
  	for (int i = 0; i < n; i++) 
  		sum1 += a[i];
  	for (int i = 0; i < n; i++) {
  		sum2 += b[i];
  	}
  }
	return sum1 + sum2;
}
