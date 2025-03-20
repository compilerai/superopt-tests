#include <errno.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/* Compliant: errno is set to 0 before calling an errno-setting function and checked after */
void compliant_sqrt(void) {
    errno = 0; /* Reset errno */
    double result = sqrt(-1.0);
    if (errno != 0) {
        printf("Error: sqrt failed with errno %d\n", errno);
    }
}

/* Non-compliant: errno is tested when the last function was not an errno-setting function */
void non_compliant_sqrt_misuse(void) {
    errno = 0;
    double result = sqrt(-1.0);
    int temp = 5; /* Non errno-setting function */
    if (errno != 0) { /* Incorrect: errno should not be checked after a non errno-setting function */
        printf("Error: Invalid errno check after non errno-setting function\n");
    }
}

/* Compliant: errno is reset before calling fopen and checked after */
void compliant_fopen(void) {
    errno = 0;
    FILE *file = fopen("non_existent.txt", "r");
    if (file == NULL && errno != 0) {
        printf("Error: fopen failed with errno %d\n", errno);
    }
}

/* Non-compliant: errno is tested when the last function was not an errno-setting function */
void non_compliant_fopen_misuse(void) {
    errno = 0;
    FILE *file = fopen("non_existent.txt", "r");
    int value = 42; /* Non errno-setting function */
    if (errno != 0) { /* Incorrect: errno should not be checked after a non errno-setting function */
        printf("Error: Invalid errno check after non errno-setting function\n");
    }
}