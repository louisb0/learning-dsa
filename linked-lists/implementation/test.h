#ifndef TEST_H
#define TEST_H

void test_create_node();
void test_free_node();
void test_create_linked_list();
void test_free_linked_list();
void test_append_empty_list();
void test_append_non_empty_list();
void test_prepend_empty_list();
void test_prepend_non_empty_list();
void test_get_valid_index();
void test_get_invalid_index();
void test_insert_at_beginning();
void test_insert_at_middle();
void test_insert_at_end();
void test_insert_at_invalid_index();
void test_remove_at_beginning();
void test_remove_at_middle();
void test_remove_at_end();
void test_remove_at_invalid_index();

void test_list_lifecycle();
void test_list_operations_order();
void test_multiple_insertions_and_removals();
void test_boundary_conditions();

void run_all_tests();

#endif // TEST_H
