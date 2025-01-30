#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

typedef struct {
    int a;
    float b;
} StructA;

int main() {
    int int_array1[3] = {1, 2, 3};
    int int_array2[3] = {1, 2, 4};
    
    unsigned int uint_array1[3] = {10U, 20U, 30U};
    unsigned int uint_array2[3] = {10U, 20U, 40U};
    
    bool bool_array1[3] = {true, false, true};
    bool bool_array2[3] = {true, false, false};
    
    Color color_array1[3] = {RED, GREEN, BLUE};
    Color color_array2[3] = {RED, GREEN, GREEN};
    
    StructA struct1 = {10, 3.14f};
    StructA struct2 = {10, 3.15f};

    // Compliant: Essentially signed type (int*)
    int result1 = memcmp(int_array1, int_array2, sizeof(int_array1));  
    printf("memcmp(int) result: %d\n", result1);

    // Compliant: Essentially unsigned type (unsigned int*)
    int result2 = memcmp(uint_array1, uint_array2, sizeof(uint_array1));  
    printf("memcmp(unsigned int) result: %d\n", result2);

    // Compliant: Essentially Boolean type (bool*)
    int result3 = memcmp(bool_array1, bool_array2, sizeof(bool_array1));  
    printf("memcmp(bool) result: %d\n", result3);

    // Compliant: Essentially enum type (Color*)
    int result4 = memcmp(color_array1, color_array2, sizeof(color_array1));  
    printf("memcmp(enum) result: %d\n", result4);

    // Non-compliant: Struct type (essentially composite type)
    int result5 = memcmp(&struct1, &struct2, sizeof(struct1));  
    printf("memcmp(struct) result: %d\n", result5);  // Struct type is not allowed

    return 0;
}
