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
     int array1[3] = {1, 2, 3};
    int result1 = binary_search(array1, 0, 2, 3);
    printf("Search 3 in {1, 2, 3}: %d\n", result1);

    int array2[5] = {2, 4, 6, 8, 10};
    int result2 = binary_search(array2, 0, 4, 6);
    printf("Search 6 in {2, 4, 6, 8, 10}: %d\n", result2);

    int array3[5] = {1, 3, 5, 7, 9};
    int result3 = binary_search(array3, 0, 4, 4);
    printf("Search 4 in {1, 3, 5, 7, 9}: %d\n", result3);

    int array4[1] = {5};
    int result4 = binary_search(array4, 0, 0, 5);
    printf("Search 5 in {5}: %d\n", result4);

    int array5[6] = {1, 3, 5, 7, 9, 11};
    int result5 = binary_search(array5, 0, 5, 12);
    printf("Search 12 in {1, 3, 5, 7, 9, 11}: %d\n", result5);

    return 0;
}