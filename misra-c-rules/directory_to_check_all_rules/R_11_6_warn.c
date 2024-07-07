/*
A cast shall not be performed between pointer to void and an arithmetic type
*/

#include <stdio.h>

int main(){
    long x = 2;
    void* p = &x;
    long r = (long) p;
    return 0;
}