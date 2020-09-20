#ifndef DETAILS_H
#define DETAILS_H

#include "types.h"


node_t create_node(string_t str, node_t next_node);

node_t remove_next(node_t* prev);

void replace(string_t* str, string_t before, string_t after);

void link_nodes(node_t* from, node_t* to);

void insert_after(node_t* pos, node_t node);

node_t find_before_min(node_t begin);

node_t find_before_greater_than(node_t begin, string_t str);

node_t find_before_equal(node_t begin, string_t str);

#endif