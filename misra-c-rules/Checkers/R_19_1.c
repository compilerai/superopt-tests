#include <stdio.h>
#include <string.h>

// Non-compliant: Overlapping memory during struct assignment
typedef struct
{
    char init_string[21];
    char new_string[101];
} string_aggr;
string_aggr my_string_aggr;
void copy()
{
    /* Non-compliant */
    strncpy(&my_string_aggr.new_string[0],&my_string_aggr.init_string[0], 100U);             
}

// Non-compliant: Overlapping memory during struct assignment
struct Example {
    int a;
    int b;
    struct Example* e;
};

void overlapping_struct_assignment() {
    struct Example obj;
    obj.a = 10;
    obj.b = 20;
    struct Example *ptr = &obj;
    ptr->e = &obj; 
    memcpy((void *)&obj.a,(void *)&obj.b,12);// Overlapping assignment (undefined behavior)
}

// Non-compliant: Overlapping memcpy operation
void overlapping_memcpy() {
    char buffer[10] = "123456789";
    memcpy(buffer, buffer, 10); // Overlapping copy (undefined behavior)
}

// Non-compliant: Overlapping memory assignment in arrays
void overlapping_array_assignment() {
    int arr[5] = {1, 2, 3, 4, 5};
    arr[1] = arr[0]; // Valid
    arr[0] = arr[1]; // Valid, but careful with ordering
    memcpy(arr, arr + 1, 3 * sizeof(int)); // Overlapping region
}

// Compliant: Proper struct assignment
void valid_struct_assignment() {
    struct Example obj1 = {1, 2};
    struct Example obj2;
    obj2 = obj1; // Proper assignment, no overlap
}

// Compliant: Proper use of memmove to handle overlapping memory
void valid_memmove() {
    char buffer[10] = "123456789";
    memmove(buffer + 2, buffer, 5); // Safe for overlapping regions
}

// Compliant: Non-overlapping memory copy
void valid_memcpy() {
    char src[5] = "abcd";
    char dest[5];
    memcpy(dest, src, 5); // No overlap, safe operation
}
