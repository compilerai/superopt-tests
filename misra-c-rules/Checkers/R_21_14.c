 
// rule : The Standard Library function memcmp shall not be used to compare null terminated strings
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
void test_memcmp() {
    // Test case 1: Comparing null-terminated strings (Should trigger the warning)
    char *str1 = "hello";
    char *str2 = "hello";
    if (memcmp(str1, str2, 5) == 0) {  // Incorrect usage (triggers checker)
        printf("The strings are equal.\n");
    }
    
 
    // Test case 2: Comparing arrays of chars that are not null-terminated (Should not trigger the warning)
    char arr1[5] = {'h', 'e', 'l', 'l', 'o'};
    char arr2[5] = {'h', 'e', 'l', 'l', 'o', '\0'};
    if (memcmp(arr1, arr2, 5) == 0) {  // Correct usage (does not trigger checker)
        printf("The arrays are equal.\n");
    }
 
    // Test case 3: Comparing two integer arrays (Should not trigger the warning)
    int arr3[3] = {1, 2, 3};
    int arr4[3] = {1, 2, 3};
    if (memcmp(arr3, arr4, sizeof(arr3)) == 0) {  // Correct usage (does not trigger checker)
        printf("The integer arrays are equal.\n");
    }
 
    // Test case 4: Using strcmp to compare null-terminated strings (Should not trigger the warning)
    if (strcmp(str1, str2) == 0) {  // Correct usage (does not trigger checker)
        printf("The strings are equal using strcmp.\n");
    }
}
 
int main() {
    test_memcmp();
    return 0;
}
 
has context menu