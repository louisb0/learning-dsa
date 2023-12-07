#include <stdio.h>

void bubble_sort(int array[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int array[] = {5, 2, 1, 2, 3};

    bubble_sort(array, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d, ", array[i]);
    }
}
