#include <stdio.h>
#include <time.h>
#include <string.h>

// Non-compliant test case: result from the first asctime() call is used after the second call.
void test_asctime_violation() {
    time_t rawtime;
    struct tm *timeinfo;
    char *result1;
    char *result2;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // First call to asctime()
    result1 = asctime(timeinfo);

    // Second call to asctime(), overwriting the previous result
    timeinfo = gmtime(&rawtime);
    result2 = asctime(timeinfo);

    // Non-compliant: using result1 after a second call to asctime()
    printf("Violation: %s\n", result1); // Violation: result1 is stale
}

// Compliant test case: the result from the first asctime() call is copied to a buffer.
void test_asctime_compliant() {
    time_t rawtime;
    struct tm *timeinfo;
    char result1[26];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // First call to asctime(), copying the result to a buffer to prevent it from becoming stale
    strcpy(result1, asctime(timeinfo));

    // Subsequent call to asctime() does not affect the copied result
    timeinfo = gmtime(&rawtime);
    printf("Compliant: %s\n", asctime(timeinfo));

    // Compliant: using the copied value from result1
    printf("Compliant (copied): %s\n", result1); // Safe usage
}

// This case tests multiple function calls to ensure the checker handles them correctly without violations
void test_multiple_calls_no_violation() {
    time_t rawtime;
    struct tm *timeinfo1, *timeinfo2;

    time(&rawtime);
    timeinfo1 = localtime(&rawtime);
    timeinfo2 = gmtime(&rawtime);

    // Call asctime but do not use the result
    asctime(timeinfo1);
    asctime(timeinfo2);

    // Compliant: no violation
}

// Test to ensure that the checker does not trigger for functions not on the tracked list
void test_non_tracked_function() {
    int a = 5;
    int b = a; // Assigning without using tracked functions

    // Should not trigger any violations
    printf("Value: %d\n", b);
}

