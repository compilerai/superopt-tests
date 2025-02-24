#include <stdio.h>
#include <stdlib.h>

// Non-Compliant Example 1: Memory not freed
void non_compliant_func1() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr) {
        *ptr = 10;
    } // Memory leak: 'ptr' is never freed
}

// Non-Compliant Example 2: File not closed
void non_compliant_func2() {
    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "Hello, World!\n");
    } // Resource leak: 'file' is never closed
}

// Non-Compliant Example 3: Memory allocated inside loop but not freed
void non_compliant_func3() {
    for (int i = 0; i < 5; i++) {
        int *arr = (int *)malloc(10 * sizeof(int)); // Allocated repeatedly
        if (arr) {
            arr[0] = i;
        } // Memory leak: 'arr' is never freed
    }
}

// Compliant Example 1: Proper memory deallocation
void compliant_func1() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr) {
        *ptr = 10;
        free(ptr); // Memory is freed
    }
}

// Compliant Example 2: File properly closed
void compliant_func2() {
    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "Hello, World!\n");
        fclose(file); // File is closed
    }
}

// Compliant Example 3: Memory allocated and freed inside loop
void compliant_func3() {
    for (int i = 0; i < 5; i++) {
        int *arr = (int *)malloc(10 * sizeof(int));
        if (arr) {
            arr[0] = i;
            free(arr); // Memory is freed
        }
    }
}