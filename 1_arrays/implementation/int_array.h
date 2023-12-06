#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stdlib.h>

typedef struct {
    int* data;
    size_t size, capacity;
} IntArray;

IntArray create_array(size_t capacity);
void insert_element(IntArray *array, int element);
int get_element(IntArray* array, int index);
void delete_element(IntArray* array, int index);
void free_array(IntArray* array);

#endif  // INT_ARRAY_H
