#include "test.h"
#include "linked_list.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Helper Functions
int compare_data(const void *a, const void *b, size_t size) {
  return memcmp(a, b, size) == 0;
}

// Test Functions
void test_create_node() {
  int data = 10;
  Node *node = create_node(&data, sizeof(data));
  assert(node != NULL);
  assert(compare_data(node->data, &data, sizeof(data)));
  free_node(node);
}

void test_create_linked_list() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  assert(list != NULL);
  assert(list->head == NULL);
  assert(list->tail == NULL);
  assert(list->length == 0);
  assert(list->size == sizeof(int));
  free_linked_list(list);
}

void test_append_empty_list() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  append(list, &data);
  assert(list->length == 1);
  assert(compare_data(list->head->data, &data, sizeof(data)));
  free_linked_list(list);
}

void test_append_non_empty_list() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data1 = 10, data2 = 20;
  append(list, &data1);
  append(list, &data2);
  assert(list->length == 2);
  assert(compare_data(list->tail->data, &data2, sizeof(data2)));
  free_linked_list(list);
}

void test_prepend_empty_list() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  prepend(list, &data);
  assert(list->length == 1);
  assert(compare_data(list->head->data, &data, sizeof(data)));
  free_linked_list(list);
}

void test_prepend_non_empty_list() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data1 = 10, data2 = 20;
  prepend(list, &data1);
  prepend(list, &data2);
  assert(list->length == 2);
  assert(compare_data(list->head->data, &data2, sizeof(data2)));
  free_linked_list(list);
}

void test_get_valid_index() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  append(list, &data);
  int *retrievedData = (int *)get(list, 0);
  assert(retrievedData != NULL);
  assert(*retrievedData == data);
  free_linked_list(list);
}

void test_get_invalid_index() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  assert(get(list, 0) == NULL);
  free_linked_list(list);
}

void test_insert_at_beginning() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  insert_at(list, &data, 0);
  assert(list->length == 1);
  assert(compare_data(list->head->data, &data, sizeof(data)));
  free_linked_list(list);
}

void test_insert_at_end() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data1 = 10, data2 = 20;
  append(list, &data1);
  insert_at(list, &data2, 1);
  assert(list->length == 2);
  assert(compare_data(list->tail->data, &data2, sizeof(data2)));
  free_linked_list(list);
}

void test_remove_at_beginning() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  append(list, &data);
  remove_at(list, 0);
  assert(list->length == 0);
  free_linked_list(list);
}

void test_remove_at_end() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  append(list, &data);
  remove_at(list, 0);
  assert(list->length == 0);
  free_linked_list(list);
}

void test_list_lifecycle() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  append(list, &data);
  int *retrievedData = (int *)get(list, 0);
  assert(retrievedData != NULL && *retrievedData == data);
  remove_at(list, 0);
  assert(list->length == 0);
  free_linked_list(list);
}

void test_list_operations_order() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data1 = 10, data2 = 20;
  append(list, &data1);
  prepend(list, &data2);
  assert(list->length == 2);
  int *retrievedData1 = (int *)get(list, 0);
  int *retrievedData2 = (int *)get(list, 1);
  assert(retrievedData1 != NULL && *retrievedData1 == data2);
  assert(retrievedData2 != NULL && *retrievedData2 == data1);
  remove_at(list, 0);
  remove_at(list, 0);
  assert(list->length == 0);
  free_linked_list(list);
}

void test_multiple_insertions_and_removals() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data1 = 10, data2 = 20, data3 = 30;
  append(list, &data1);
  prepend(list, &data2);
  insert_at(list, &data3, 1);
  assert(list->length == 3);
  remove_at(list, 1);
  assert(list->length == 2);
  int *retrievedData = (int *)get(list, 0);
  assert(retrievedData != NULL && *retrievedData == data2);
  free_linked_list(list);
}

void test_boundary_conditions() {
  DoublyLinkedList *list = create_linked_list(sizeof(int));
  int data = 10;
  assert(get(list, 0) == NULL);
  assert(remove_at(list, 0) == NULL);
  append(list, &data);
  assert(get(list, -1) == NULL);
  assert(remove_at(list, -1) == NULL);
  free_linked_list(list);
}

void run_all_tests() {
  test_create_node();
  test_create_linked_list();
  test_append_empty_list();
  test_append_non_empty_list();
  test_prepend_empty_list();
  test_prepend_non_empty_list();
  test_get_valid_index();
  test_get_invalid_index();
  test_insert_at_beginning();
  test_insert_at_end();
  test_remove_at_beginning();
  test_remove_at_end();
  test_list_lifecycle();
  test_list_operations_order();
  test_multiple_insertions_and_removals();
  test_boundary_conditions();

  printf("All tests passed!\n");
}

int main() {
  run_all_tests();
  return 0;
}
