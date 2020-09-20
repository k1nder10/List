#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "test.h"


void print_workflow() {
    puts("Creating a list...");

    node_t head = NULL;
    StringListInit(&head, "s6");
    StringListAdd(&head, "s5");
    StringListAdd(&head, "s4");
    StringListAdd(&head, "s1");
    StringListAdd(&head, "s4");
    printf("List: ");
    StringListPrint(head);
    puts(" ");

    printf("Size of list: %d\n", StringListSize(head));
    printf("Index of s1: %d\n", StringListIndexOf(head, "s1"));
    printf("Index of Hello: %d\n", StringListIndexOf(head, "Hello"));
    puts(" ");

    puts("Removing all s4 entries...");
    StringListRemove(&head, "s4");
    printf("List: ");
    StringListPrint(head);
    puts(" ");

    puts("Adding new elements...");
    StringListAdd(&head, "s5");
    StringListAdd(&head, "s5");
    StringListAdd(&head, "s6");
    StringListAdd(&head, "s1");
    StringListAdd(&head, "s3");
    printf("List: ");
    StringListPrint(head);
    puts(" ");

    puts("Removing duplicates...");
    StringListRemoveDuplicates(&head);
    printf("List: ");
    StringListPrint(head);
    puts(" ");

    puts("Replacing all s1 entries by s8...");
    StringListReplaceInStrings(&head, "s1", "s8");
    printf("List: ");
    StringListPrint(head);
    puts(" ");

    puts("Sorting...");
    StringListSort(&head);
    printf("List: ");
    StringListPrint(head);

    StringListDestroy(&head);
}


int main() {
    test_init_destroy();
    test_size();
    test_add();
    test_remove();
    test_last_index_of();
    test_remove_duplicates();
    test_replace_in_strings();
    test_sort();
    
    puts("\n---------------------------");
    puts("Workflow:\n");
    print_workflow();
    
    return 0;
}