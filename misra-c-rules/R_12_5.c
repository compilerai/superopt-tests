/*
    The sizeof operator shall not have an operand which is a function parameter declared as "array of type".
*/
#include<stdio.h>


int main(){
    char a[] = "Hello";
    int size = sizeof(a); // sizeof is allowed for normal array of type which are not functional arguments
    return 0;
}