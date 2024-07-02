#include<string.h>
#include<stdio.h>
void bitwise_tests(int x ) {
    int a = 5;
    int b = 10;
    _Bool c=1;
    _Bool d=0;

    // Correct usage
    int result1 = a & b;
    int result2 = a | b;
    
    // Incorrect usage
    int e = c & d;
    int f=  c | d;
}
int main(){
    bitwise_tests((_Bool)5 & (_Bool)7);
    printf("Operands shall not be of an inappropriate essential type");
}
