#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "list.h"


static void test_init_destroy() {
    enum { value, next };

    node_t head = NULL;
    StringListInit(&head, "s1");
    assert(head != NULL);
    assert(strcmp(head[value], "s1") == 0);

    StringListDestroy(&head);
    assert(head == NULL);

    puts("test_init_destroy: OK");
}


static void test_size() {
    node_t head = NULL;
    assert(StringListSize(head) == 0);

    StringListInit(&head, "s5");
    assert(StringListSize(head) == 1);

    StringListDestroy(&head);
    puts("test_size: OK");
}


static void test_last_index_of() {
    node_t head = NULL;
    StringListInit(&head, "s1");
    StringListAdd(&head, "s3");
    assert(StringListIndexOf(head, "s5") == -1);
    assert(StringListIndexOf(head, "s1") == 0);
    assert(StringListIndexOf(head, "s3") == 1);

    StringListDestroy(&head);
    puts("test_last_index_of: OK");
}


static void test_add() {
    node_t head = NULL;
    StringListInit(&head, "s5");
    assert(StringListSize(head) == 1);

    StringListAdd(&head, "s3");
    assert(StringListSize(head) == 2);

    StringListDestroy(&head);
    puts("test_add: OK");
}


static void test_remove() {
    node_t head = NULL;
    StringListInit(&head, "s5");
    StringListInit(&head, "s5");
    StringListRemove(&head, "s5");
    assert(StringListSize(head) == 0);

    StringListAdd(&head, "s4");
    StringListRemove(&head, "s4");
    assert(StringListSize(head) == 0);

    StringListDestroy(&head);
    puts("test_remove: OK");
}


static void test_remove_duplicates() {
    node_t head = NULL;
    StringListInit(&head, "s5");
    StringListAdd(&head, "s5");
    StringListAdd(&head, "s5");
    StringListAdd(&head, "s4");
    StringListAdd(&head, "s4");
    StringListAdd(&head, "s000");
    StringListAdd(&head, "s2");
    StringListAdd(&head, "s2");
    assert(StringListSize(head) == 8);

    StringListRemoveDuplicates(&head);
    assert(StringListSize(head) == 4);
    
    StringListDestroy(&head);
    puts("test_remove_duplicates: OK");
}


static void test_replace_in_strings() {
    enum { value };

    node_t head = NULL;
    StringListInit(&head, "Hello, World!");
    StringListReplaceInStrings(&head, "World", "man");
    assert(strcmp(head[value], "Hello, man!") == 0);

    StringListReplaceInStrings(&head, "man!", "");
    assert(strcmp(head[value], "Hello, ") == 0);

    StringListReplaceInStrings(&head, "Hello, ", "");
    assert(strcmp(head[value], "") == 0);

    StringListReplaceInStrings(&head, "", "Hello, World!");
    assert(strcmp(head[value], "Hello, World!") == 0);

    StringListDestroy(&head);
    puts("test_replace_in_strings: OK");
}


static void test_sort() {
    enum { value };

    node_t head = NULL;
    StringListInit(&head, "s5");
    StringListAdd(&head, "s4");
    StringListAdd(&head, "s1");
    StringListAdd(&head, "s2");
    StringListSort(&head);

    assert(strcmp(head[value], "s1") == 0);

    StringListDestroy(&head);
    puts("test_sort: OK");
}