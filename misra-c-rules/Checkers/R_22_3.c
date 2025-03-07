#include <stdio.h>
#include <stdlib.h>

// Non-Compliant Example 1: Same file opened in different streams for reading and writing
void non_compliant_func1() {
    FILE *file1 = fopen("example.txt", "r");
    if(!file1) return;
    FILE *file2 = fopen("example.txt", "w"); // Undefined behavior: same file opened for read and write
    if(!file2) return;
    fprintf(file2, "Hello, World!\n");
    fclose(file1);
    fclose(file2);
}

// Non-Compliant Example 2: Opening the same file in append and read mode separately
void non_compliant_func2() {
    FILE *file1 = fopen("example.txt", "r");
    if(!file1) return;
    FILE *file2 = fopen("example.txt", "w"); // Undefined behavior: same file opened for read and write
    if(!file2) return;   
    fputs("New Line\n", file2);
    fclose(file1);
    fclose(file2);
}

// Compliant Example 1: Properly closing before reopening
void compliant_func1() {
    FILE *file = fopen("example.txt", "r");
    if(!file) return;
    fclose(file);
    file = fopen("example.txt", "w");
    if(!file) return;
    fprintf(file, "Safe Writing\n");
    fclose(file);
}

// Compliant Example 2: Using a single file stream at a time
void compliant_func2() {
    FILE *file = fopen("example.txt", "r+"); // Opened in read/write mode correctly
    if (!file) return;
    fprintf(file, "Updated content\n");
    fclose(file);
}