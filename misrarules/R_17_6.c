#include <stdio.h>

// Correct usage: static keyword between [ ]
void processArray(int arr[static 10]) {
    // Function body omitted for brevity
    printf("Processing array...\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Call to function with array parameter
    processArray(arr);
    printf("The declaration of an array parameter shall not contain the static keyword between the [ ]");
    return 0;
}
