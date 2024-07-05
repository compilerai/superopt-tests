#include <stdio.h>

// Function declarations
void funcA(int n);
void funcB(int n);
void funcC(int n);

void funcA(int n) {
    if (n > 0) {
        printf("funcA: %d\n", n);
        funcB(n - 1);
    }
}

void funcB(int n) {
    if (n > 0) {
        printf("funcB: %d\n", n);
        funcC(n - 1);
    }
}

void funcC(int n) {
    if (n > 0) {
        printf("funcC: %d\n", n);
        funcA(n - 1);
    }
}

// Function declarations
int isEven(int n);
int isOdd(int n);

int isEven(int n) {
    if (n == 0) {
        return 1; // 0 is even
    } else {
        return isOdd(n - 1); // Check the next lower number
    }
}

int isOdd(int n) {
    if (n == 0) {
        return 0; // 0 is not odd
    } else {
        return isEven(n - 1); // Check the next lower number
    }
}
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


int main() {
    int number = 5;
    funcA(number);
    if (isEven(number)) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }
    if (number < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d = %llu\n", number, factorial(number));
    }  
    printf("Functions shall not call themselves, either directly or indirectly");
    return 0;
}
