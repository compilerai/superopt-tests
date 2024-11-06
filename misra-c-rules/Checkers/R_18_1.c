

void test_valid_within_bounds() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    // Valid: Points to an element within the bounds
    p = p + 2;  // Now pointing to arr[2]
}
void test_valid_one_past_end() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    // Valid: Points the last element, allowed by the C standard
    p = p + 4;  // Points to arr + 4, just past the end
}
void test_invalid_beyond_end() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    // Invalid: Points beyond the array bounds
    p = p + 6;  // Points to arr + 6, which is out of bounds
}
void test_invalid_before_start() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr + 3;

    // Invalid: Points before the start of the array
    p = p - 4;  // Points to arr[-1], which is out of bounds
}
void test_valid_traverse_array() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    // Valid: Looping through the array within bounds
    for (int i = 0; i < 5; ++i) {
        int value = *(p + i);  // Points to arr[i], within bounds
    }
}

