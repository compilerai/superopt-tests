#include <stdio.h>

void test_compliant_within_same_array() {
    int arr[10];
    int *p1 = &arr[2];
    int *p2 = &arr[5];

    // Compliant: Both pointers point within the same array
    if (p1 < p2) {
        printf("Compliant comparison within the same array.\n");
    }
}

void test_non_compliant_different_objects() {
    int var1 = 10;
    int var2 = 20;
    int *p4 = &var1;
    int *p5 = &var2;

    // Non-compliant: Comparing pointers to different objects
    if (p4 < p5) {  // This violates the rule
        printf("Non-compliant comparison between different objects.\n");
    }
}

void test_non_compliant_different_types() {
    int arr[10];
    int *p1 = &arr[2];
    int var1 = 10;
    int *p4 = &var1;

    // Non-compliant: Comparing pointers not pointing into the same object
    if (p1 > p4) {  // This violates the rule
        printf("Non-compliant comparison between array and standalone variable.\n");
    }
}

void test_compliant_equality_inequality() {
    int var1 = 10;
    int var2 = 20;
    int *p4 = &var1;
    int *p5 = &var2;

    // Compliant: Equality and inequality comparisons are allowed
    if (p4 == p5 || p4 != p5) {
        printf("Compliant equality/inequality comparison.\n");
    }
}