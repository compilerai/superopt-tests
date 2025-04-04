#include <stdio.h>

void non_compliant_usage() {
    int *ptr = NULL;
    int num;

    num = (int)ptr;  // Non-compliant: Converting pointer to int
    ptr = (int *)1000;  // Non-compliant: Assigning an integer to a pointer
    printf("Pointer value: %d\n", num);
}

void compliant_usage() {
    int value = 10;
    int *ptr = &value; // Compliant: Pointer stores valid object address

    uintptr_t addr = (uintptr_t)ptr; // Compliant: Using <stdint.h> uintptr_t
    printf("Pointer address: %lu\n", (unsigned long)addr);
}

int main() {
    non_compliant_usage();
    compliant_usage();
    return 0;
}
