#include <stdio.h>

// Non-compliant: Missing return statement in one path
int missing_return(int x) {
    if (x > 0) {
        if(x>4)
        {
            int c;
        }else{
            return 1;
        }
    }
    else{
        return 9;
    }
    // No return statement here
}

// Non-compliant: Function lacks a return statement completely
int no_return_statement() {
    // No return statement at all
}

// Non-compliant: Return without an expression in a non-void function
int return_without_expression() {
    return; // Invalid: No expression provided
}

// Compliant: All paths have explicit return statements
int valid_function(int x) {
    if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

// Compliant: A single return statement at the end ensures all paths return a value
int another_valid_function(int x) {
    if (x > 0) {
        printf("Positive\n");
    }
    return 0; // Ensures return in all cases
}

// Compliant: Ternary operator ensuring a return value
int valid_with_ternary(int x) {
    return (x > 0) ? 1 : -1;
}

int main() {
    printf("%d\n", valid_function(5));
    printf("%d\n", another_valid_function(-3));
    printf("%d\n", valid_with_ternary(0));
    return 0;
}