#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This implementation covers the conceptual implementation of a linked list,
// and is memory safe (i.e. no leaks). However, we do not properly handle cases
// that would be encountered in practicality. For example, failure to malloc()
// a list or node. We just fail silently.
//
// We just fail silently here, which would cause the consumer of our interface
// to eventually crash at a later stage (i.e. get() silently returning NULL).
//
// Since no one is ever going to use this code, I'm fine with it. I'm going to
// cover these kind of cases in the upcoming HTTP server.

typedef struct Node {
  void *data;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  int length;
  size_t size;
} DoublyLinkedList;

Node *create_node(const void *data, const size_t size) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    return NULL;
  }

  node->data = malloc(size);
  memcpy(node->data, data, size);
  node->prev = node->next = NULL;

  return node;
}

void free_node(Node *node) {
  if (node != NULL) {
    free(node->data);
    free(node);
  }
}

DoublyLinkedList *create_linked_list(const size_t size) {
  DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
  if (list == NULL) {
    return NULL;
  }

  list->size = size;
  list->length = 0;
  list->head = list->tail = NULL;

  return list;
}

void free_linked_list(DoublyLinkedList *list) {
  Node *current = list->head;

  while (current != NULL) {
    Node *tmp = current->next;
    free_node(current);
    current = tmp;
  }

  free(list);
}

void append(DoublyLinkedList *list, void *data) {
  Node *node = create_node(data, list->size);

  if (list->length == 0) {
    list->head = list->tail = node;
  } else {
    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
  }

  list->length++;
}

void prepend(DoublyLinkedList *list, void *data) {
  Node *node = create_node(data, list->size);

  if (list->length == 0) {
    list->head = list->tail = node;
  } else {
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
  }

  list->length++;
}

void insert_at(DoublyLinkedList *list, void *data, int index) {
  if (list == NULL || index < 0 ||
      index > list->length) { // '>' to allow for size 3 insert at 4
    return;
  }

  Node *to_insert = create_node(data, list->size);
  if (to_insert == NULL) {
    return;
  }

  if (index == 0) {
    prepend(list, data);
  } else if (index == list->length) {
    append(list, data);
  } else {
    // We can't use get() here, as get() returns the dereferenced
    // data by design.
    Node *current = list->head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }

    to_insert->next = current;
    to_insert->prev = current->prev;
    current->prev->next = to_insert;
    current->prev = to_insert;

    list->length++;
  }
}

void *get(DoublyLinkedList *list, int index) {
  if (list == NULL || index < 0 || index >= list->length) {
    return NULL;
  }

  Node *node = list->head;
  for (int i = 0; i < index; i++) {
    if (node == NULL) {
      return NULL;
    }

    node = node->next;
  }

  return node->data;
}

void *remove_at(DoublyLinkedList *list, int index) {
  if (list == NULL || index < 0 || index >= list->length) {
    return NULL;
  }

  // We can't use get() here, as get() returns the dereferenced
  // data by design.
  Node *to_remove = list->head;
  for (int i = 0; i < index; i++) {
    if (to_remove == NULL) {
      return NULL;
    }

    to_remove = to_remove->next;
  }

  if (to_remove->prev) {
    to_remove->prev->next = to_remove->next;
  } else {
    list->head = to_remove->next;
  }

  if (to_remove->next) {
    to_remove->next->prev = to_remove->prev;
  } else {
    list->tail = to_remove->prev;
  }

  void *data = malloc(list->size);
  if (data == NULL) {
    return NULL;
  }
  memcpy(data, to_remove->data, list->size);

  free_node(to_remove);
  list->length--;

  return data;
}

void print_linked_list(DoublyLinkedList *list) {
  for (int i = 0; i < list->length; i++) {
    printf("%d, ", *(int *)get(list, i));
  }
  printf("\n");
}
