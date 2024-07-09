#include <stdio.h>

static void CompliantExample(int value) {
    switch (value) {
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2\n");
            break;
        case 3:
            printf("Case 3\n");
            break;
        default:
            printf("Default case\n");
    }
}

static void NonCompliantExample(int value){
    switch (value) {
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2\n");
            break;
        case 3:
            printf("Case 3\n");
        default:
            printf("Default case\n");
    }   
}

int main(void) {
    return 0;
}