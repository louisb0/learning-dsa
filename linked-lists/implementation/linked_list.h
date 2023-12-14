#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

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

Node *create_node(const void *data, const size_t size);
void free_node(Node *node);

DoublyLinkedList *create_linked_list(const size_t size);
void free_linked_list(DoublyLinkedList *list);

void append(DoublyLinkedList *list, void *data);
void prepend(DoublyLinkedList *list, void *data);
void *get(DoublyLinkedList *list, int index);

void insert_at(DoublyLinkedList *list, void *data, int index);
void *remove_at(DoublyLinkedList *list, int index);

void print_linked_list(DoublyLinkedList *list);

#endif // LINKED_LIST_H
