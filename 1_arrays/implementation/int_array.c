#include "int_array.h"

#include <stdlib.h>
#include <stdio.h>

IntArray create_array(size_t capacity) {
    IntArray array;

    array.data = (int*)calloc(capacity, sizeof(int));
    array.capacity = capacity;
    array.size = 0;

    return array;
}

void insert_element(IntArray *array, int element) {
    if (array->size == array->capacity) {
        array->capacity += 1;
        array->data =
            (int *)realloc(array->data, array->capacity * sizeof(int));
    }

    // array->data[array->size] = element;
    *(array->data + array->size) = element;
    array->size++;
}

int get_element(IntArray* array, int index) {
    if (index < array->size && index >= 0) {
        return *(array->data + index);
    } else {
        printf("Invalid index for get_element().\n");
        exit(EXIT_FAILURE);
    }
}

void delete_element(IntArray* array, int index) {
    if (index < array->size && index >= 0) {
        *(array->data + index) = 0;
    } else {
        printf("Invalid index for delete_element().\n");
        exit(EXIT_FAILURE);
    }
}

void free_array(IntArray* array) {
    free(array->data);
    array->data = NULL;
    array->capacity = 0;
    array->size = 0;
}
