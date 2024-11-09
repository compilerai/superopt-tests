void test_valid_subtraction_same_array() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p1 = &arr[1];
    int *p2 = &arr[4];

    // Valid: Both pointers point to elements within the same array
    int diff = p2 - p1;  // Result should be 3 (difference in elements)
}
void test_valid_subtraction_same_pointer() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p1 = &arr[3];

    // Valid: Subtracting the same pointer results in zero
    int diff = p1 - p1;  // Result should be 0
}
void test_invalid_subtraction_different_arrays() {
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    int *p1 = &arr1[1];
    int *p2 = &arr2[1];

    // Invalid: p1 and p2 point to elements in different arrays
    int diff = p2 - p1;  // Undefined behavior
}
void test_valid_subtraction_multi_dimensional() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *p1 = &arr[0][1];
    int *p2 = &arr[1][1];

    // valid: p1 and p2 are from  same array
    int diff = p2 - p1; 
}
void test_valid_subtraction_same_row() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *p1 = &arr[0][0];
    int *p2 = &arr[0][2];

    // Valid: p1 and p2 point to elements within the same subarray (row)
    int diff = p2 - p1;  // Result should be 2
}

