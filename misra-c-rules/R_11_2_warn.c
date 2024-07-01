/*
Conversions shall not be performed between a pointer to incomplete and any other type
*/

#include <stdio.h>

struct some_incomplete;

int main() {
    struct some_incomplete *ptr;
    int* x = (int*)ptr; // this should raise a warning
    return 0;
}