#include <stdio.h>

void test_case_1() {
    // Test Case 1: Attempt to use a file pointer after closing the file
    printf("Running Test Case 1\n");
    FILE *fp = fopen("example1.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file in Test Case 1\n");
        return;
    }

    // Write to the file
    fprintf(fp, "Hello, world!\n");

    // Close the file
    fclose(fp);

    // Attempt to use the file pointer after it is closed
    fprintf(fp, "This should not work!\n");  // Violation: Using the pointer after fclose()
}

void test_case_2() {
    // Test Case 2: Attempt to read from a file pointer after closing the file
    printf("Running Test Case 2\n");
    FILE *fp = fopen("example2.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file in Test Case 2\n");
        return;
    }

    // Read from the file
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);

    // Close the file
    fclose(fp);

    // Attempt to read again after closing the file
    fgets(buffer, sizeof(buffer), fp);  // Violation: Using the pointer after fclose()
}

void test_case_3() {
    // Test Case 3: Attempt to seek on a file pointer after closing the file
    printf("Running Test Case 3\n");
    FILE *fp = fopen("example3.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file in Test Case 3\n");
        return;
    }

    // Close the file
    fclose(fp);

    // Attempt to use fseek after the file is closed
    fseek(fp, 0, SEEK_SET);  // Violation: Using the pointer after fclose()
}

void test_case_4() {
    // Test Case 4: Attempt to flush a closed file stream
    printf("Running Test Case 4\n");
    FILE *fp = fopen("example4.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file in Test Case 4\n");
        return;
    }

    // Write to the file
    fprintf(fp, "Flushing this data!\n");

    // Close the file
    fclose(fp);

    // Attempt to flush after the file is closed
    fflush(fp);  // Violation: Using the pointer after fclose()
}

void test_case_5() {
    // Test Case 5: Safe case (Valid Use)
    printf("Running Test Case 5\n");
    FILE *fp = fopen("example5.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file in Test Case 5\n");
        return;
    }

    // Write to the file
    fprintf(fp, "This is a valid use.\n");

    // Close the file
    fclose(fp);

    // Do not use the pointer after fclose()
    // Optionally, reset the pointer to avoid accidental usage
    fp = NULL;  
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
