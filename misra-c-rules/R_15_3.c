#include <stdio.h>

static void test1(void) {
    goto label;
    printf("This will be skipped.\n");
label:
    printf("test1 label\n\n");
}

static void test2(void) {
    int x = 5;
    if (x > 0) {
        goto label;
    }
label:
    printf("Goto statement works correctly in test2 label \n\n");
}

static void test3(void) {
    int x = 5;
    if (x > 0) {
        goto label;
    }
    if (x < 0) {
label:
        printf("This will never be executed in test3.\n");
    }
}

static void test4(void) {
    int x = 5;
    if (x > 0) {
        goto label;
    } else {
        label:
            printf("test4 label \n\n");
    }
}

static void test5(void) {
    int x = 5;
    if (x > 0) {
        goto label;
        if (x < 0) {
        label:
            printf("test5 Label\n\n");            
        }
        goto else_label;
    } else {
        else_label:
            printf("test5 else Label\n\n");            
    }
}

int main(void) {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}