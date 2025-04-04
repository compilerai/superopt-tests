#include <stdio.h>
#include <stdlib.h>

// ✅ Compliant Code: Static allocation
void compliantExample() {
    int arr[10]; // Allowed: Stack allocation
    arr[0] = 5;
    printf("%d\n", arr[0]);
}

// ❌ Non-Compliant Code: malloc()
void testMalloc() {
    int *ptr = (int *)malloc(10 * sizeof(int));  // Violation
    if (ptr) {
        ptr[0] = 42;
        free(ptr);  // Still a violation
    }
}

// ❌ Non-Compliant Code: calloc()
void testCalloc() {
    int *ptr = (int *)calloc(10, sizeof(int));  // Violation
    if (ptr) {
        ptr[0] = 42;
        free(ptr);  // Still a violation
    }
}

// ❌ Non-Compliant Code: realloc()
void testRealloc() {
    int *ptr = (int *)malloc(5 * sizeof(int));  // Violation
    if (ptr) {
        ptr = (int *)realloc(ptr, 10 * sizeof(int));  // Violation
        if (ptr) {
            ptr[0] = 99;
            free(ptr);
        }
    }
}

// ❌ Non-Compliant Code: free()
void testFree() {
    int *ptr = (int *)malloc(10 * sizeof(int));  // Violation
    if (ptr) {
        free(ptr);  // Violation (implies dynamic allocation)
    }
}

int main() {
    compliantExample();
    testMalloc();
    testCalloc();
    testRealloc();
    testFree();
    return 0;
}
