#include <stdio.h>


int binary_search(int array[], int low_index, int high_index, int target) {
    while (low_index <= high_index) {
        int midpoint_index = low_index + (high_index - low_index) / 2;
        int midpoint_value = array[midpoint_index];

        if (target == midpoint_value) {
            return midpoint_index;
        } else if (target < midpoint_value) {
            high_index = midpoint_index - 1;
        } else {
            low_index = midpoint_index + 1;
        }
    } 

    return -1;
}


int main() {
    int array[3] = {1,2,3};
    int result = binary_search(array, 0, 2, 3);

    printf("%d", result);
}