/*
A cast shall not be performed between pointer to void and an arithmetic type
*/

#include <stdio.h>

int main(){
    int x = 2;
    void* p = &x;
    int r = (int) p;
    return 0;
}