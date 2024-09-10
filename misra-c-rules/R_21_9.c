#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int main() {
    // Test qsort
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before qsort: ");
    for (size_t i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, arr_size, sizeof(int), compare_ints);

    printf("Array after qsort: ");
    for (size_t i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test bsearch
    int key = 5;
    int *item;

    item = (int *)bsearch(&key, arr, arr_size, sizeof(int), compare_ints);

    if (item != NULL) {
        printf("Element %d found in the array.\n", *item);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
