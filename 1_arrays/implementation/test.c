#include "test.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "int_array.h"

void test_insert_element() {
    // Test inserting into an empty array
    IntArray array = create_array(1);
    insert_element(&array, 10);
    assert(array.size == 1);
    assert(array.capacity == 1);
    assert(get_element(&array, 0) == 10);

    // Test capacity increase
    insert_element(&array, 20);
    assert(array.size == 2);
    assert(array.capacity > 1);
    assert(get_element(&array, 1) == 20);

    // Cleanup
    free_array(&array);
}

void test_get_element() {
    // Setup array
    IntArray array = create_array(2);
    insert_element(&array, 10);
    insert_element(&array, 20);

    // Test getting valid elements
    assert(get_element(&array, 0) == 10);
    assert(get_element(&array, 1) == 20);

    // Cleanup
    free_array(&array);
}

void test_delete_element() {
    IntArray array = create_array(2);
    insert_element(&array, 10);
    insert_element(&array, 20);

    // Test deleting a valid element
    delete_element(&array, 0);
    assert(get_element(&array, 0) == 0);

    free_array(&array);
}

int main() {
    test_insert_element();
    test_delete_element();
    test_get_element();

    printf("All tests passed.\n");

    return 0;
}
