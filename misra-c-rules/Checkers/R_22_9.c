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

/* Non-compliant: errno is not tested after calling an errno-setting function */
void non_compliant_sqrt(void) {
    errno = 0;
    double result = sqrt(-1.0);
    /* Missing check for errno after function call */
}

/* Compliant: errno is reset before calling fopen and checked after */
void compliant_fopen(void) {
    errno = 0;
    FILE *file = fopen("non_existent.txt", "r");
    if (file == NULL && errno != 0) {
        printf("Error: fopen failed with errno %d\n", errno);
    }
}

/* Non-compliant: errno is not tested after calling fopen */
void non_compliant_fopen(void) {
    errno = 0;
    FILE *file = fopen("non_existent.txt", "r");
    /* Missing check for errno after function call */
}