#ifndef LIST_H
#define LIST_H

#include "types.h"

/* Initializes list */
void StringListInit(node_t*, string_t);

/* Destroy list and set pointer to NULL. */
void StringListDestroy(node_t*);

/* Inserts value at the end of the list. */
void StringListAdd(node_t*, string_t);

/* Removes all occurrences of str in the list. */
void StringListRemove(node_t*, string_t);

/* Returns the number of items in the list. */
int StringListSize(node_t);

/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(node_t, string_t);

/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(node_t*);

/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(node_t* head, string_t before, string_t after);

/* Sorts the list of strings in ascending order */
void StringListSort(node_t*);

/* Prints the list */
void StringListPrint(node_t);

#endif