#include<string.h>
#include<stdio.h>
void R_9_5_tests() {
    int a[]={ [0]=4,4};  //should generatte warning
    int b[3]={[0]=1, [2]=3, [1]=1000};
    int c[]={2,3,4,5};
    int d[4]={1,2,4};
}
int main(){
    R_9_5_tests();
    printf("Where designated initialisers are used to initialize an array object the size of the array shall be specified explicitly");
}
