#define LEN 32000
#define LEN1 3200
#define LEN2 1024
#define LEN3 256

#define TYPE int

__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],dd[LEN2][LEN2],tmp[LEN2][LEN2], aaa[LEN3][LEN3][LEN3], bbb[LEN3][LEN3][LEN3];
TYPE x,y;

//sum3d
TYPE ex6u(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN3; i++)
	  for (int j = 0; j < LEN3; j++)
      #pragma GCC unroll 2
	    for (int k = 0; k < LEN3; k++)
		    ret += aaa[i][j][k];
	return ret;
}
