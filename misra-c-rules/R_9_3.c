#include <stdio.h>

// Test case 1: Partial initialization of a global array
int globalArray1[5] = {1, 2, 3}; // Violation

// Test case 2: Partial initialization of a local array
void testLocalArray() {
    int localArray[3] = {1, 2}; // Violation
    // Use of localArray
    printf("Local Array: {%d, %d, %d}\n", localArray[0], localArray[1], localArray[2]);
}

// Test case 3: Full initialization of a global array
int globalArray2[3] = {1, 2, 3}; // Correct

// Test case 4: Full initialization of a local array
void testLocalArrayFull() {
    int localArray[4] = {1, 2, 3, 4}; // Correct
    // Use of localArray
    printf("Local Array Full: {%d, %d, %d, %d}\n", localArray[0], localArray[1], localArray[2], localArray[3]);
}

// Test case 5: Mixed initialization of a global array
int globalArray3[4] = {1, 2}; // Violation

int main() {
    // Test case 1: Partially initialized global array
    printf("Global Array 1: {%d, %d, %d, %d, %d}\n", globalArray1[0], globalArray1[1], globalArray1[2], globalArray1[3], globalArray1[4]);
    
    // Test case 2: Partially initialized local array
    testLocalArray();
    
    // Test case 3: Fully initialized global array
    printf("Global Array 2: {%d, %d, %d}\n", globalArray2[0], globalArray2[1], globalArray2[2]);
    
    // Test case 4: Fully initialized local array
    testLocalArrayFull();
    
    // Test case 5: Mixed initialized global array
    printf("Global Array 3: {%d, %d, %d, %d}\n", globalArray3[0], globalArray3[1], globalArray3[2], globalArray3[3]);
    printf("Arrays shall not be partially initialized");
    return 0;
}
