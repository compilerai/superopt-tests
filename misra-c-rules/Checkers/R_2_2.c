#include <stdio.h>

// Non-Compliant Example 1: Dead code due to unused variable
void non_compliant_func1() {
    int x = 5; // Dead code: 'x' is never used
}

// Non-Compliant Example 2: Dead code due to redundant computation
int non_compliant_func2() {
    int a = 10;
    int b = 20;
    int c = a + b; // Dead code: 'c' is never used
    return a;
}

// Non-Compliant Example 3: Dead code due to an unused variable after execution
void non_compliant_func3() {
    int i = 0;
    while (i < 5) {
        i++;
    }
    int unused_var = 10; // Dead code: this variable is never used
}

// Non-Compliant Example 4: Dead code due to redundant computation
int non_compliant_func4() {
    int x = 20; // Dead code: 'x' is assigned but never used meaningfully
    return 10;
}

// Non-Compliant Example 5: Dead code due to an unused statement
void non_compliant_func5() {
    int a = 5; // Dead code: 'a' is never used
    printf("Executed\n"); // Only meaningful statement
}

// Non-Compliant Example 6: Dead code due to function that is never called
void non_compliant_func6() {
    printf("This function is never called, so it's dead code.\n");
}

// Non-Compliant Example 7: Dead code due to not required this function
void non_compliant_func7() {
    non_compliant_func6();
}

// Compliant Example 1: Properly using variables
int compliant_func1() {
    int x = 5;
    return x; // 'x' is used, so it's not dead code
}

// Compliant Example 2: Meaningful computation with used result
int compliant_func2() {
    int a = 10;
    int b = 20;
    int c = a + b;
    return c; // The computation result is used
}

// Compliant Example 3: Valid conditional execution
void compliant_func3(int n) {
    if (n > 0) {
        printf("Valid execution path\n");
    }
}

// Compliant Example 4: Proper loop execution
void compliant_func4() {
    for (int i = 0; i < 5; i++) {
        printf("Iteration %d\n", i);
    }
}

// Compliant Example 5: Function that is actually called
void compliant_func5() {
    printf("This function is actually used.\n");
}


