#include<stdio.h>
int func(){
  return 42;
}
void R_13_1_tests(){
  int a = 5;
  int b = 10;
  int c;
  int arr[4]={[1]=a,[0]=b,[3]=c,[2]=4};
  int arr0[]={a,b};    
  int arr1[] = {a, b, (c = 20)}; // Should raise warning
  int arr2[] = {a, b, ++a};      // Should raise warning
  int arr3[]= {a,b, func()};     // Should raise warning
}
int main(){
    R_13_1_tests();
    printf("Initialiser lists shall not contain persistent side effects.");
}
