#include <stdio.h>
#include <string.h>


// Function to test violation using fwrite on a read-only file
void test_fwrite_read_only() {
    FILE *file = fopen("read_only.txt", "r");
    if (!file) {
        perror("Error opening read-only file");
        return;
    }

    // Violation: Attempt to write using fwrite to a read-only file
    const char *data = "This is a test using fwrite.\n";
    fwrite(data, sizeof(char), strlen(data), file);

    fclose(file);
}
// Function to test violation using fprintf on a read-only file
void test_fprintf_read_only() {
    FILE *file = fopen("read_only.txt", "r");
    if (!file) {
        perror("Error opening read-only file");
        return;
    }

    // Violation: Attempt to write using fprintf to a read-only file
    fprintf(file, "This is a test using fprintf.\n");

    fclose(file);
}
// Function to test violation using fputs on a read-only file
void test_fputs_read_only() {
    FILE *file = fopen("read_only.txt", "r");
    if (!file) {
        perror("Error opening read-only file");
        return;
    }

    // Violation: Attempt to write using fprintf to a read-only file
    fputs("This is a test using fprintf.\n",file);

    fclose(file);
}

// Function to test non-violation using fputs on a read-only file
void test_fread_read_only() {
    FILE *file = fopen("read_only.txt", "r");
    if (!file) {
        perror("Error opening read-only file");
        return;
    }
    // non-Violation: Attempt to read using fread to a read-only file
    char buffer[100];
    fread(buffer, sizeof(char), sizeof(buffer), file);

    fclose(file);
}

// Function to test non-violation using fprintf on a writable file
void test_fprintf_write() {
    FILE *file = fopen("write.txt", "w");
    if (!file) {
        perror("Error opening write file");
        return;
    }

    // Non-violation: Writing to a file opened in write mode using fprintf
    fprintf(file, "This is a test using fprintf.\n");

    fclose(file);
}

// Function to test non-violation using fwrite on a writable file
void test_fwrite_write() {
    FILE *file = fopen("write.txt", "w");
    if (!file) {
        perror("Error opening write file");
        return;
    }

    // Non-violation: Writing to a file opened in write mode using fwrite
    const char *data = "This is a test using fwrite.\n";
    fwrite(data, sizeof(char), strlen(data), file);

    fclose(file);
}

// Function to test non-violation using fputs on a writable file
void test_fputs_write() {
    FILE *file = fopen("write.txt", "w");
    if (!file) {
        perror("Error opening write file");
        return;
    }

    // Non-violation: Writing to a file opened in write mode using fputs
    fputs("This is a test using fputs.\n", file);

    fclose(file);
}

