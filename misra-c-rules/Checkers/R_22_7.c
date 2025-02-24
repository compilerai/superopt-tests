#include <stdio.h>
#include <stdlib.h>

// Non-Compliant Example 1: Comparing EOF with a modified return value
void non_compliant_func1() {
    int ch = getchar();
    ch += 1; // Modifying the return value
    if (ch == EOF) { // Undefined behavior
        printf("Error detected\n");
    }
}

// Non-Compliant Example 2: Using EOF incorrectly in an assignment before comparison
void non_compliant_func2() {
    int ch;
    if ((ch = getchar()) != EOF) { // Correct usage
        ch = ch + 1; // Modified return value
    }
    if (ch == EOF) { // Incorrect comparison
        printf("Error detected\n");
    }
}

// Compliant Example 1: Proper EOF check without modification
void compliant_func1() {
    int ch = getchar();
    if (ch == EOF) { // Correct comparison
        printf("End of file reached or error occurred\n");
    }
}

// Compliant Example 2: EOF check with correct return value handling
void compliant_func2() {
    FILE *file = fopen("example.txt", "r");
    if (!file) return;
    int ch;
    while ((ch = fgetc(file)) != EOF) { // Correct usage
        putchar(ch);
    }
    fclose(file);
}