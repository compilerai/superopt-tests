/*
A loop counter shall not have essentially floating type
*/
#include <stdio.h>


int main(){
  // for(int i = 0;i<3;i++){
  //   printf("Hello World, Don't know why this is giving long error\n"); 
  // }
  for (double A = 0.1, B = 0.2 ;A <= 0.5; A = A +0.1) {
    printf("We have a float loop counter\n");
  }

  return 0;
}
