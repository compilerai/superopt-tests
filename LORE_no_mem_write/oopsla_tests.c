

#define LEN 32000
#define LEN1 3200
#define LEN2 1024
#define LEN3 256

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
#include "eqchecker_helper.h"


#define TYPE int

__attribute__((aligned(16))) TYPE a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],dd[LEN2][LEN2],tmp[LEN2][LEN2], aaa[LEN3][LEN3][LEN3], bbb[LEN3][LEN3][LEN3];
TYPE x,y;

//sum1d
TYPE ex1(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN; i++)
		ret += a[i];
	return ret;
}

//sum2d
TYPE ex2(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN2; i++)
	  for (int j = 0; j < LEN2; j++)
		  ret += aa[i][j];
	return ret;
}

//sum3d
TYPE ex7(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN3; i++)
	  for (int j = 0; j < LEN3; j++)
	    for (int k = 0; k < LEN3; k++)
		    ret += aaa[i][j][k];
	return ret;
}

//sum2d-1d
TYPE ex3(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN2; i++)
	  for (int j = 0; j < LEN2; j++)
		 ret += aa[i][j];
	for (int i = 0; i < LEN; i++)
		ret += a[i];
	return ret;
}

//sum2d-1d-imperfect
TYPE ex4(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN2; i++) {
	  for (int j = 0; j < LEN2; j++)
		  ret += aa[i][j];
		ret += a[i];
  }
	return ret;
}

//sum1d-2d
TYPE ex5(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN; i++)
		ret += a[i];
	for (int i = 0; i < LEN2; i++)
	  for (int j = 0; j < LEN2; j++)
		  ret += aa[i][j];
	return ret;
}

//MW-1d
TYPE ex101(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN; i++)
		b[i] += a[i];
	return ret;
}

//MW-2d
TYPE ex102(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN2; i++)
	  for (int j = 0; j < LEN2; j++)
		  bb[i][j] += aa[i][j];
	return ret;
}

//MW-3d
TYPE ex107(){
	for (int i = 0; i < LEN3; i++)
	  for (int j = 0; j < LEN3; j++)
	    for (int k = 0; k < LEN3; k++)
		    bbb[i][j][k] = aaa[i][j][k];
	return 0;
}

//MW-2d-1d
TYPE ex103(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN2; i++)
	  for (int j = 0; j < LEN2; j++)
		 bb[i][j] += aa[i][j];
	for (int i = 0; i < LEN; i++)
		b[i] += a[i];
	return ret;
}

//MW-2d-1d-imperfect
TYPE ex104(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN2; i++) {
	  for (int j = 0; j < LEN2; j++)
		  bb[i][j] += aa[i][j];
	  b[i] += a[i];
  }
	return ret;
}

//MW-1d-2d
TYPE ex105(){
	TYPE ret = 0.;
	for (int i = 0; i < LEN; i++)
		b[i] += a[i];
	for (int i = 0; i < LEN2; i++)
	  for (int j = 0; j < LEN2; j++)
		  bb[i][j] += aa[i][j];
	return ret;
}

//3-way branch 1D loop
//Sum
int ex9()
{

  int sum = 0;
	for (int i = 0; i < LEN; i++) {
		if (d[i] < (TYPE)0.) {
			sum--;
		} else if (d[i] == (TYPE)0.) {
			sum = sum;
		} else {
			sum++;
		}
	}
	return sum;
}

//3-way branch 1D loop
//MW
int ex109()
{

	 for (int i = 0; i < LEN; i++) {
	 	if (d[i] < (TYPE)0.) {
	 		a[i] += b[i] * c[i];
	 	} else if (d[i] == (TYPE)0.) {
	 		a[i] += b[i] * b[i];
	 	} else {
	 		a[i] += c[i] * c[i];
	 	}
	 }
	return 0;
}


//2-way branch 1D loop
//MW
void ex1011 ()
{
  int i;
  for (i = 0; i < LEN; i++)
    b[i] = a[i] < 0 ? x : y;
}

//2-way branch 1D loop
//Sum
int ex11 ()
{
  int i;
  int sum = 0;
  for (i = 0; i < LEN; i++)
    sum += a[i] < 0 ? x : y;
  return sum;
}


int alpha, beta;
//loop 2D (sum-MW-MW) imperfect
//Store sinking removed
void ex12()
//void kernel_atax()
{
  int i, j;

  for (i = 0; i < LEN2; i++)
  {
    int sum1 = 0;
    for (j = 0; j < LEN2; j++)
      sum1 += aa[i][j] * b[j];
    e[i] = sum1;
    for (j = 0; j < LEN2; j++)
      c[j] += aa[i][j] * e[i];
  }
}

//loop 2D (sum-MW) perfect
void ex13()
//void kernel_atax()
{
  int i, j;

  for (i = 0; i < LEN2; i++)
  {
    int sum1 = 0;
    for (j = 0; j < LEN2; j++)
      sum1 += aa[i][j] * b[j];
    for (j = 0; j < LEN2; j++)
      c[j] += aa[i][j] * sum1;
  }
}

//loop 2D (sum-MW) imperfect
//Store sinking removed
void ex14()
//void kernel_gesummv()
{
  int i, j;
  for (i = 0; i < LEN2; i++)
  {
    int sum1 = 0;
    int sum2 = 0;
    for (j = 0; j < LEN2; j++)
    {
      sum1 += aa[i][j] * c[j];
      sum2 += bb[i][j] * c[j];
    }
    b[i] = alpha * sum1 + beta * sum2;
  }
}


//loop 2D (sum-sum MW) imperfect
//Store sinking removed
void ex16()
//void kernel_mvt()
{
  int i, j;

  for (i = 0; i < LEN2; i++) {
    int sum1 = a[i]; int sum2 = b[i];
    for (j = 0; j < LEN2; j++)
      sum1 += aa[i][j] * b[j];
    for (j = 0; j < LEN2; j++)
      sum2 += aa[j][i] * b[j];
    a[i] = sum1;
    b[i] = sum2;
  }
}

//test-suite/SingleSource/UnitTests/Vectorizer/  --  GCC test suite

//loop 3D (2-sum MW) imperfect 
void ex18()
//void example14() 
{
  int k,j,i=0;
  int len = LEN3;
  for (k = 0; k < len; k++) {
    int sum = 0;
    for (i = 0; i < len; i++)
      for (j = 0; j < len; j++)
          sum += aaa[k][i][j];

    a[k] = sum;
  }

}


int main(){

	return 0;
}

