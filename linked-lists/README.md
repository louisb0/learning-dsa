> The [implementation](./implementation/linked_list.c) lacks a few things like proper error handling - i.e. we just return NULL in the case of an error. I will be covering these control flows in an HTTP server project, and I want to focus more on the data structures and understanding memory here.

# linked_lists

A linked list is a `node` based data structure. A `node` in a linked list contains a few properties;

- The data contained in the node, `data`
- A pointer to the next node, `next`
- A pointer to the previous node, `prev`

We're defining a data structure which may be interacted with, and a `node` is an internal part of that structure, encapsulating the users' `data`. The user should only interact with operations defined by the linked list, and not the nodes themselves.

```
(a)  -> (b)  -> (c)  -> (d)                 -- singly
(a) <-> (b) <-> (c) <-> (d)                 -- doubly
```

The linked list itself defines only these properties;

- The `length` of the list, the number of `node`'s contained
- The `head`, the first `node` in the list (`(a)` in the above)
- The `tail`, the last `node` in the list (`(b)` in the above)

## Fundamental Operations

We have a few fundamental operations, which extend on our [previous definition of an array](../arrays/README.md), which had a fixed length and no true delete operation. Linked lists improve on this by being dynamic in size, and being able to truly delete data from the structure (rather than overriding with a sentinel value, like in our arrays implementation).

> These exclude some edge cases for brevity, but, they are covered in the [implementation](./implementation/linked_list.c).

**T get(int index):** This will start at `list->head`, and iterate forward to the `index`th `node`, then returning the value of `node->data`.

- In a lower level implementation, we need to be careful to validate the index, otherwise we will attempt to access `->data` of a null pointer, causing a segfault.

**void insert_at(int index, T data):** Add a `node` in the place of `index`. There are a few cases here (simplified down a bit):

- Insert at head (`prepend`): We set `list->head->prev = new_node`, `new_node->next = list->head`, and then `list->head = new_node`. That is: set our `new_node` as the head, ensure it's `next` is the old head, and that our old head `prev` points to our `new_node`.
- Insert at tail (`append`): We set `list->tail->next = new_node`, `new_node->prev = list->tail`, and then `list->tail = new_node`.
- Insert at index (middle):

  1. Locate `current_node` using `get()` (in practicality, `get()` returns the data and not the node, so we'd need to replicate the logic)
  2. Set `new_node->next = current_node`, `new_node->prev = current_node->prev`
  3. Set `current_node->prev->next = new_node` (if `current_node->prev != NULL`, else if `current_node->prev == NULL, set list->head = new_node`)
  4. Set `current_node->prev = new_node`

**void remove_at(int index):** Remove the node at position `index`.

1. Locate `node_to_remove` using `get()` (same practicality disclaimer as above)
2. If `node_to_remove->prev != NULL`, set `node_to_remove->prev->next = node_to_remove->next`. Else, set `list->head = node_to_remove->next`.
3. If `node_to_remove->next != NULL`, set `node_to_remove->next->prev = node_to_remove->prev`. Else, set `list->tail = node_to_remove->prev`.
4. `free(node_to_remove)`

## Complexity of fundamental operations

1. `get()`: This is O(n) worst case, i.e. we have to traverse using `node->next` until we get to the `tail`.
2. `insert_at()`: This is limited by `get()`, and is hence `O(n).`
   - If the target node that lives at `index` was known, this operation would be `O(1)`.
3. `remove_at()`: This is limited again by `get()`, and is hence `O(n)`.
   - If the target node that lives at `index` was known, this operation would be `O(1)`.

The time complexity of linked lists vary based on implementation. Each implementation has its tradeoffs, i.e. if we expose `node` to the consumers of our methods, they can break the internal structure and cause segfaults or other issues. But, in order to make insert and remove operations O(1), the consumer of the interface must own a pointer to the target node(s).
