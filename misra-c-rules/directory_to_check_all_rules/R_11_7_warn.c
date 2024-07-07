/*
A cast shall not be performed between 
pointer to object and a non-integer arithmetic type
*/


#include <stdio.h>

int main(){
    int x = 2;
    int* p = &x;
    double r = (double) p;
    return 0;
}