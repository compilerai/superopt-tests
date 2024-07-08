#include<stdio.h>
void R_18_8_tests(){
  int cs=4,s=4;
  int array1[10];         
  int array2[];  
  int array3[s];        // should raise warning
  int array4[4*10+500];
}
int main(){
    R_18_8_tests();
    printf("Variable-length array types shall not be used");
}
