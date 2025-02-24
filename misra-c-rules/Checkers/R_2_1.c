#include <stdio.h>

// Non-Compliant Example 1: Code after return statement (Unreachable)
int non_compliant_func1() {
    printf("Executing non_compliant_func1\n");
    return 0;
    printf("This line is unreachable\n"); // Non-compliant
}

// Non-Compliant Example 2: Unreachable loop
void non_compliant_func2() {
    return;
    while (1) { // Non-compliant: This loop will never execute
        printf("This will never print\n");
    }
}

// Non-Compliant Example 3: Dead Code after Infinite Loop
void non_compliant_func3() {
    while (1) {
        printf("Infinite loop\n");
    }
    printf("Unreachable statement\n"); // Non-compliant
}

// Non-Compliant Example 4: Unreachable break statement
void non_compliant_func4() {
    while (1) {
        printf("Inside loop\n");
        break;
        printf("This will never execute\n"); // Non-compliant
    }
}

// Compliant Example 1: Properly structured function
int compliant_func1() {
    printf("Executing compliant_func1\n");
    return 1;
}

// Compliant Example 2: Properly structured loop
void compliant_func2(int x) {
    if (x > 0) {
        printf("Valid code\n");
    } else {
        printf("Another valid branch\n");
    }
}

// Compliant Example 3: Properly structured loop with return inside condition
int compliant_func3(int n) {
    if (n > 0) {
        return n;
    }
    return 0;
}

// Compliant Example 4: Function without unreachable code
void compliant_func4() {
    for (int i = 0; i < 5; i++) {
        printf("Iteration %d\n", i);
    }
}

int main() {
    non_compliant_func1();
    non_compliant_func2();
    non_compliant_func3();
    non_compliant_func4();
    
    compliant_func1();
    compliant_func2(5);
    compliant_func3(3);
    compliant_func4();
    return 0;
}