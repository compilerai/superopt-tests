#include <stdio.h>
#include <stdlib.h>  // Non-compliant: Including <stdlib.h> for memory functions

void non_compliant_usage() {
    int *ptr1 = (int *)malloc(10 * sizeof(int));  // Non-compliant
    int *ptr2 = (int *)calloc(10, sizeof(int));   // Non-compliant
    ptr1 = (int *)realloc(ptr1, 20 * sizeof(int)); // Non-compliant
    free(ptr1);  // Non-compliant
    free(ptr2);  // Non-compliant
}

void compliant_usage() {
    int arr[10]; // Compliant: Using stack memory
    static int staticArr[20]; // Compliant: Using static memory
}

int main() {
    non_compliant_usage();
    compliant_usage();
    return 0;
}