#include <stdio.h>
#include <stdlib.h>


void sampleFunc(void) {
    printf("sampleFunc function called.\n");
}

// Function to test exit()
void test_exit(void) {
    printf("Inside test_exit().\n");
    exit(EXIT_SUCCESS); // Program terminates with success status
}

// Function to test abort()
void test_abort(void) {
    printf("Inside test_abort().\n");
    abort(); // Program terminates abnormally
}

// Function to test quick_exit()
void test_quick_exit(void) {
    printf("Inside test_quick_exit().\n");
    quick_exit(EXIT_SUCCESS); // Program terminates quickly without calling atexit functions
}

int main() {
    // Register a function to be called on normal program termination
    if (atexit(sampleFunc) != 0) {
        fprintf(stderr, "Failed to register sampleFunc function\n");
        return EXIT_FAILURE;
    }

    // Call each test function
    printf("Testing exit()\n");
    test_exit();

    // Uncomment to test abort()
    // printf("Testing abort()\n");
    // test_abort();

    // Uncomment to test quick_exit()
    // printf("Testing quick_exit()\n");
    // test_quick_exit();

    return EXIT_SUCCESS;
}



