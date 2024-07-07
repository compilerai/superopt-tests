/*
A loop counter shall not have essentially floating type
*/
#include <stdio.h>


int main(){
  // for(int i = 0;i<3;i++){
  //   printf("Hello World, Don't know why this is giving long error\n"); 
  // }
  for (float A = 0.1f; A <= 10.0f; A += 0.1f) {
    printf("We have a float loop counter\n");
  }

  return 0;
}
