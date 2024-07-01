/*
    The sizeof operator shall not have an operand which is a function parameter declared as "array of type".
*/
#include<stdio.h>
void f(int a[]){
    int size = sizeof(a); // this should raise a warning.
}


int main(){
    return 0;
}