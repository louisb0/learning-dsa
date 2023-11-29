#include <stdio.h>

int linear_search(int *items, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (*(items + i) == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = linear_search(arr, size, target);
    if (result != -1) {
        printf("Element found at: %d\n", result);
    } else {
        printf("Element not found\n");
    }
}