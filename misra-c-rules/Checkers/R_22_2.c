#include <stdio.h>
#include <stdlib.h>

// Test Case 1: Correct usage of malloc and free
void test_malloc_free() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    if (ptr != NULL) {
        free(ptr); // Compliant: memory allocated with malloc is freed
    }
}

// Test Case 2: Correct usage of calloc and free
void test_calloc_free() {
    int *ptr = (int *)calloc(10, sizeof(int));
    if (ptr != NULL) {
        free(ptr); // Compliant: memory allocated with calloc is freed
    }
}

// Test Case 3: Correct usage of realloc and free
void test_realloc_free() {
    int *ptr = (int *)malloc(sizeof(int) * 5);
    if (ptr != NULL) {
        ptr = (int *)realloc(ptr, sizeof(int) * 10);
        free(ptr); // Compliant: memory reallocated with realloc is freed
    }
}

// Test Case 4: Freeing memory not allocated by malloc, calloc, or realloc
void test_invalid_free() {
    int localVar = 0;
    int *ptr = &localVar;
    free(ptr); // Non-compliant: memory not allocated by malloc, calloc, or realloc
}


