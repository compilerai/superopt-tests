#include <stdio.h>

// Global variable
int globalVar = 10;

// Test case 1: Function with parameter hiding global variable
void testFunction(int globalVar) {
    printf("Inside testFunction: globalVar = %d\n", globalVar); // Local parameter
}

// Test case 2: Nested block with variable hiding outer variable
void testNestedBlock() {
    int x = 5;   
    {
        int x = 8; // Hides outer 'x'
        printf("Inside nested block: x = %d\n", x); // Prints inner 'x'
    }
    printf("Outside nested block: x = %d\n", x); // Prints outer 'x'
}

// Test case 3: Function with local variable hiding global variable
void testLocalGlobalVar() {
    int globalVar = 15; // Hides global 'globalVar'
    printf("Inside testLocalGlobalVar: globalVar = %d\n", globalVar); // Prints local 'globalVar'
}

int main() {
    // Test case 1: Function with parameter hiding global variable
    printf("Global variable: globalVar = %d\n", globalVar);
    testFunction(20); // Call with parameter

    // Test case 2: Nested block with variable hiding outer variable
    testNestedBlock();

    // Test case 3: Function with local variable hiding global variable
    printf("Global variable: globalVar = %d\n", globalVar);
    testLocalGlobalVar();
    printf("An identifier declared in an inner scope shall not hide an identifier declared in an outer scope.");
    return 0;
}
