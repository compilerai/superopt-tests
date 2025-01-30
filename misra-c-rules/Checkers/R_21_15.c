#include <string.h>
#include <stdio.h>

typedef struct {
    int a;
    float b;
} StructA;

typedef struct {
    int a;
    float b;
} StructB;  // Compatible with StructA

int main() {
    char src[] = "Hello, World!";
    char dest[20];

    // Compliant: Same type (char arrays)
    memcpy(dest, src, sizeof(src));
    printf("dest: %s\n", dest);

    //  Non-compliant: Copying incompatible types
    int int_array1[5] = {1, 2, 3, 4, 5};
    float float_array2[5];
    memcpy(float_array2, int_array1, sizeof(int_array1));  //  Wrong: int* → float*

    // Non-Compliant: Compatible struct types
    StructA s1 = {10, 3.14f};
    StructB s2;
    memcpy(&s2, &s1, sizeof(s1));  // Wrong: StructA and StructB are not-compatible

    //  Non-compliant: Struct vs. array
    memcpy(&s1, src, sizeof(s1));  // Wrong: struct* → char*

    // Compliant: Same type (char* → char*)
    memmove(dest, src, sizeof(src));

    // Non-compliant: Comparing different types
    int result = memcmp(int_array1, float_array2, sizeof(int_array1));  // Wrong: int* → float*
    printf("memcmp result: %d\n", result);

    return 0;
}
