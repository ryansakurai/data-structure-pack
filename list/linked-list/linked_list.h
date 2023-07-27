/**
 *  Linked implementation of a list
 * 
 *  Author: Ryan Sakurai
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct LLNode {
    T data;
    struct LLNode *prev;
    struct LLNode *next;
} LLNode;

typedef struct LinkedList {
    LLNode *sentinel;
    unsigned size;
} LinkedList;

typedef struct LLIterator {
    LinkedList *list;
    LLNode *current_item;
} LLIterator;

/**
 * Initializes the list
 * 
 * Parameters
 * - LinkedList *list
 * 
 * Returns: void
 */
void ll_init(LinkedList *list);

/**
 * Destroys the list
 * 
 * Parameters
 * - LinkedList *list
 * 
 * Returns: void
 */
void ll_destroy(LinkedList *list);

/**
 * Pushes an item to the first place of the list
 * 
 * Parameters
 * - LinkedList *list
 * - T data: data to be pushed to the list
 * 
 * Returns: void
 */
void ll_push_first(LinkedList *list, T data);

/**
 * Pushes an item to the last place of the list
 * 
 * Parameters
 * - LinkedList *list
 * - T data: data to be pushed to the list
 * 
 * Returns: void
 */
void ll_push_last(LinkedList *list, T data);

/**
 * Pops the first item off the list and stores it in a variable
 * 
 * Parameters
 * - LinkedList *list
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool ll_pop_first(LinkedList *list, T *output);

/**
 * Pops the last item off the list and stores it in a variable
 * 
 * Parameters
 * - LinkedList *list
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool ll_pop_last(LinkedList *list, T *output);

/**
 * Stores the first item of the list in a variable
 * 
 * Parameters
 * - LinkedList list
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool ll_get_first(LinkedList list, T *output);

/**
 * Stores the last item of the list in a variable
 * 
 * Parameters
 * - LinkedList list
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool ll_get_last(LinkedList list, T *output);

/**
 * Returns the size of the list
 * 
 * Parameters
 * - LinkedList list
 * 
 * Returns: unsigned
 * - The size of the list
 */
unsigned ll_get_size(LinkedList list);

/**
 * Returns if the list is empty
 * 
 * Parameters
 * - LinkedList list
 * 
 * Returns: bool
 * - If the list is empty
 */
bool ll_is_empty(LinkedList list);

/**
 * Initializes the iterator in a list
 * 
 * Parameters
 * - LLIterator *iter
 * - LinkedList *list: list the iterator will point to
 * 
 * Returns: bool
 * - True if it was possible to initialize it
 * - False if the list is empty and it wasn't possible
 */
bool ll_iter_init(LLIterator *iter, LinkedList *list);

/**
 * Moves the iterator to the next item in the list
 * 
 * Parameters
 * - LLIterator *iter
 * 
 * Returns: bool
 * - True if it was possible
 * - False if the end of the list was reached and it wasn't possible
 */
bool ll_iter_next(LLIterator *iter);

/**
 * Stores the item currently being pointed by the iterator in a variable
 * 
 * Parameters
 * - LLIterator iter
 * - T *output - variable where the item is going to be stored
 * 
 * Returns: bool
 * - True, if it was possible to get the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool ll_get_current_item(LLIterator iter, T *output);

/**
 * Pushes an item before the item currently being pointed by the iterator
 * 
 * Parameters
 * - LLIterator *iter
 * - T data: data to be pushed to the list
 * 
 * Returns: bool
 * - True, if it was possible to push the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool ll_push_before_current_item(LLIterator *iter, T data);

/**
 * Pushes an item after the item currently being pointed by the iterator
 * 
 * Parameters
 * - LLIterator *iter
 * - T data: data to be pushed to the list
 * 
 * Returns: bool
 * - True, if it was possible to push the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool ll_push_after_current_item(LLIterator *iter, T data);

/**
 * Pops and stores the item currently being pointed by the iterator in a variable
 * 
 * Parameters
 * - LLIterator *iter
 * - T *output: variable where the item is going to be stored
 * 
 * Returns: bool
 * - True, if it was possible to pop the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool ll_pop_current_item(LLIterator *iter, T *output);

/**
 * Moves the iterator to a certain item, if it's possible to find it
 * 
 * Parameters
 * - LinkedList *iter
 * - bool (*equals)(void *a, void *b): function used to find the item
 * - T key: key to be searched for
 * 
 * Returns: bool
 * - If it was possible to find it
 */
bool ll_search(LLIterator *iter, bool (*equals)(void *a, void *b), T key);

#endif
