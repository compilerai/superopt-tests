#include <stdio.h>
#include <stdlib.h>

// Non-Compliant Example 1: Same file opened in different streams for reading and writing
void non_compliant_func1() {
    FILE *file1 = fopen("example.txt", "r");
    FILE *file2 = fopen("example.txt", "w"); // Undefined behavior: same file opened for read and write
    if (file1 && file2) {
        fprintf(file2, "Hello, World!\n");
        fclose(file1);
        fclose(file2);
    }
}

// Non-Compliant Example 2: Opening the same file in append and read mode separately
void non_compliant_func2() {
    FILE *file1 = fopen("example.txt", "r");
    FILE *file2 = fopen("example.txt", "a"); // Undefined behavior: simultaneous access in different modes
    if (file1 && file2) {
        fputs("New Line\n", file2);
        fclose(file1);
        fclose(file2);
    }
}

// Compliant Example 1: Properly closing before reopening
void compliant_func1() {
    FILE *file = fopen("example.txt", "r");
    if (file) {
        fclose(file); // Close before reopening in a different mode
    }
    file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "Safe Writing\n");
        fclose(file);
    }
}

// Compliant Example 2: Using a single file stream at a time
void compliant_func2() {
    FILE *file = fopen("example.txt", "r+"); // Opened in read/write mode correctly
    if (file) {
        fprintf(file, "Updated content\n");
        fclose(file);
    }
}