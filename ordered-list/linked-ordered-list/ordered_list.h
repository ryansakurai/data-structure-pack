/**
 *  Linked implementation of an ascending ordered list
 * 
 *  Author: Ryan Sakurai
 */

#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct OLNode {
    T data;
    struct OLNode *prev;
    struct OLNode *next;
} OLNode;

typedef struct OrderedList {
    OLNode *sentinel;
    unsigned size;
    int (*compare)(T a, T b);
} OrderedList;

typedef struct OLIterator {
    OrderedList *list;
    OLNode *current_item;
} OLIterator;

/**
 * Initializes the list
 * 
 * Parameters
 * - OrderedList *list
 * - int (*compare)(T a, T b): function used to compare items (positive if a is greater, 0 if equal and negative if b is greater)
 * 
 * Returns: void
 */
void ol_init(OrderedList *list, int (*compare)(T a, T b));

/**
 * Destroys the list
 * 
 * Parameters
 * - OrderedList *list
 * 
 * Returns: void
 */
void ol_destroy(OrderedList *list);

/**
 * Pushes an item to the list, following its order
 * 
 * Parameters
 * - OrderedList *list
 * - T data: data to be pushed to the list
 * 
 * Returns: void
 */
void ol_push(OrderedList *list, T data);

/**
 * Pops the first item off the list and stores it in a variable
 * 
 * Parameters
 * - OrderedList *list
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool ol_pop_first(OrderedList *list, T *output);

/**
 * Pops the last item off the list and stores it in a variable
 * 
 * Parameters
 * - OrderedList *list
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool ol_pop_last(OrderedList *list, T *output);

/**
 * Stores the first item of the list in a variable
 * 
 * Parameters
 * - OrderedList list
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool ol_get_first(OrderedList list, T *output);

/**
 * Stores the last item of the list in a variable
 * 
 * Parameters
 * - OrderedList list
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool ol_get_last(OrderedList list, T *output);

/**
 * Returns the size of the list
 * 
 * Parameters
 * - OrderedList list
 * 
 * Returns: unsigned
 * - The size of the list
 */
unsigned ol_get_size(OrderedList list);

/**
 * Returns if the list is empty
 * 
 * Parameters
 * - OrderedList list
 * 
 * Returns: bool
 * - If the list is empty
 */
bool ol_is_empty(OrderedList list);

/**
 * Initializes the iterator in a list
 * 
 * Parameters
 * - OLIterator *iter
 * - OrderedList *list: list the iterator will point to
 * 
 * Returns: bool
 * - True if it was possible to initialize it
 * - False if the list is empty and it wasn't possible
 */
bool ol_iter_init(OLIterator *iter, OrderedList *list);

/**
 * Moves the iterator to the next item in the list
 * 
 * Parameters
 * - OLIterator *iter
 * 
 * Returns: bool
 * - True if it was possible
 * - False if the end of the list was reached and it wasn't possible
 */
bool ol_iter_next(OLIterator *iter);

/**
 * Stores the item currently being pointed by the iterator in a variable
 * 
 * Parameters
 * - OLIterator iter
 * - T *output - variable where the item is going to be stored
 * 
 * Returns: bool
 * - True, if it was possible to get the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool ol_get_current_item(OLIterator iter, T *output);

/**
 * Pops and stores the item currently being pointed by the iterator in a variable
 * 
 * Parameters
 * - OLIterator *iter
 * - T *output: variable where the item is going to be stored
 * 
 * Returns: bool
 * - True, if it was possible to pop the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool ol_pop_current_item(OLIterator *iter, T *output);

#endif
