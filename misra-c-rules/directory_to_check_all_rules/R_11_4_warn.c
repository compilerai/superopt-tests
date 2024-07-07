/*
A conversion should not be performed between a pointer to object and an integer type
*/
 

#include <stdio.h>

int main() {    
    int num = 42;
    int *ptr = &num;
    int address = (int)ptr; // Not compliant: converting a pointer to an integer
    int *new_ptr = (int *)num; // Not compliant: converting an integer to a pointer 
}
