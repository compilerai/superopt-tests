/*
Conversions shall not be performed between a pointer to a function and any other type
*/
#include <stdio.h>

void my_function(int a) {
    printf("Value: %d\n", a);
}

int main() {
    void (*func_ptr)(int) = my_function; // this is a pointer to a function 
    int* x = (int*)func_ptr; // this should raise a warning
    return 0;
}