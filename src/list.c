#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"
#include "details.h"


enum { value, next };


void StringListInit(node_t* head, string_t str) {
    *head = create_node(str, NULL);
}


void StringListDestroy(node_t* head) {
    if (*head == NULL) return;

    node_t prev = *head;
    node_t curr = (node_t)(prev[next]);

    while (curr != NULL) {
        free(prev[value]);
        free(prev);

        prev = (node_t)curr;
        curr = (node_t)curr[next];
    }

    free(prev[value]);
    free(prev);

    *head = NULL;
}


void StringListAdd(node_t* head, string_t str) {
    if (*head == NULL) return;

    node_t curr = *head;
    while (curr[next] != NULL) {
        curr = (node_t)curr[next];
    }

    node_t new_node = create_node(str, NULL);
    curr[next] = (string_t)new_node;
}


void StringListRemove(node_t* head, string_t str) {
    if (*head == NULL) return;

    node_t prev = *head;
    node_t curr = (node_t)(prev[next]);

    while (curr != NULL) {
        if (strcmp(curr[value], str) == 0) {
            curr = remove_next(&prev);
            continue;
        }

        prev = curr;
        curr = (node_t)curr[next];
    }

    // remove head
    if (strcmp((*head)[value], str) == 0) {
        node_t new_head = (node_t)(*head)[next];
        free((*head)[value]);
        free(*head);
        *head = new_head;
    }
}


int StringListSize(node_t head) {
    int size = 0;

    while (head != NULL) {
        head = (node_t)head[next];
        size += 1;
    }

    return size;
}


int StringListIndexOf(node_t head, string_t str) {
    int index = 0;

    while (head != NULL) {
        if (strcmp(head[value], str) == 0) break;

        head = (node_t)head[next];
        index += 1;
    }

    if (head == NULL) return -1;
    return index;
}


void StringListRemoveDuplicates(node_t* head) {
    node_t curr = *head;
    node_t remove_pos = NULL;

    while (curr != NULL) {
        while ((remove_pos = find_before_equal(curr, curr[value])) != NULL) {
            remove_next(&remove_pos);
        }
        
        curr = (node_t)curr[next];
    }
}


void StringListReplaceInStrings(node_t* head, string_t before, string_t after) {
    node_t curr = *head;

    while (curr != NULL) {
        replace(&curr[value], before, after);
        curr = (node_t)curr[next];
    }
}


void StringListSort(node_t* head) {
    if (*head == NULL) return;
    if ((*head)[next] == NULL) return;

    node_t curr = *head;
    node_t before_min = NULL;
    node_t insert_pos = *head;

    while (curr != NULL) {
        before_min = find_before_min(curr);

        // if min element isn't in the current node
        if (before_min) {
            node_t min = (node_t)before_min[next];
            node_t after_min = (node_t)min[next];

            link_nodes(&before_min, &after_min);
            insert_after(&insert_pos, min);

            insert_pos = (node_t)insert_pos[next];
        }
        
        curr = (node_t)curr[next];
    }

    // insert head to the right position
    node_t pos = find_before_greater_than((*head), (*head)[value]);
    if (pos == *head) return;

    node_t temp = *head;
    *head = (node_t)(*head)[next];
    insert_after(&pos, temp);
}


void StringListPrint(node_t head) {
    if (head == NULL) {
        puts("null");
        return;
    }

    while (head[next] != NULL) {
        printf("%s -> ", head[value]);
        head = (node_t)head[next];
    }
    printf("%s -> ", head[value]);

    puts("null");
}