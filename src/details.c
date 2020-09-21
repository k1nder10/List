#include <string.h>
#include <stdlib.h>

#include "details.h"


enum { value, next };


node_t create_node(string_t str, node_t next_node) {
    node_t node = (node_t)malloc(sizeof(string_t) + sizeof(pointer_t));
    
    if (str != NULL) {
        const size_t size = strlen(str) + 1;
        node[value] = (string_t)malloc(size);
        memcpy(node[value], str, size);
    }
    else {
        node[value] = NULL;
    }

    node[next] = (pointer_t)next_node;

    return node;
}


void link_nodes(node_t* from, node_t* to) {
    (*from)[next] = (pointer_t)(*to);
}


node_t remove_next(node_t* prev) {
    if ((*prev) == NULL) return NULL;
    if ((*prev)[next] == NULL) return NULL;

    node_t middle = (node_t)(*prev)[next]; // removes this node
    node_t next_node = (node_t)middle[next];

    link_nodes(prev, &next_node);
    free(middle[value]);
    free(middle);

    return next_node;
}


void replace(string_t* str, string_t before, string_t after) {
    string_t before_address = strstr(*str, before);
    if (!before_address) return;

    const size_t before_len = strlen(before);
    const size_t after_len = strlen(after);
    string_t remainder = before_address + before_len;
    const size_t remainder_len = strlen(remainder);

    // number of symbols from the beginning to the before string
    const size_t symbols_between = (before_address - &(*str)[0]);

    // if after string is greater than before one we must create a new string
    if (after_len > before_len) {
        const size_t new_str_size = strlen(*str) - before_len + after_len + 1;
        string_t new_str = (string_t)malloc(new_str_size);

        memcpy(new_str, *str, symbols_between);
        memcpy(new_str + symbols_between, after, after_len);
        memcpy(new_str + symbols_between + after_len, remainder, remainder_len);

        free(*str);
        *str = new_str;
        (*str)[new_str_size - 1] = 0;
    }

    // otherwise we can reuse the old memory
    else if (after_len < before_len) {
        memcpy(before_address, after, after_len);
        memcpy(before_address + after_len, remainder, remainder_len);
        (*str)[symbols_between + after_len + remainder_len] = 0;
    }
    else {
        memcpy(before_address, after, after_len);
    }
}


void insert_after(node_t* pos, node_t node) {
    if (*pos != NULL && node != NULL) {
        node[next] = (*pos)[next];
        (*pos)[next] = (pointer_t)node;
    }
}


node_t find_before_min(node_t begin) {
    string_t min = begin[value];
    node_t before_min = NULL; // returns NULL if min is in the begin
    node_t curr = (node_t)begin[next];
    node_t prev = begin;

    while (curr != NULL) {
        if (strcmp(curr[value], min) < 0) {
            min = curr[value];
            before_min = prev;
        }

        curr = (node_t)curr[next];
        prev = (node_t)prev[next];
    }

    return before_min;
}


node_t find_before_greater_than(node_t begin, string_t str) {
    node_t prev = begin;
    node_t curr = (node_t)begin[next];

    while (curr != NULL) {
        if (strcmp(curr[value], str) > 0) {
            return prev;
        }

        prev = (node_t)prev[next];
        curr = (node_t)curr[next];
    }

    return prev; // otherwise returns last node
}


node_t find_before_equal(node_t begin, string_t str) {
    node_t prev = begin;
    node_t curr = (node_t)begin[next];

    while (curr != NULL) {
        if (strcmp(curr[value], str) == 0) {
            return prev;
        }

        prev = (node_t)prev[next];
        curr = (node_t)curr[next];
    }

    return NULL;
}