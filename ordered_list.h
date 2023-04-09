/**
 *  Linked implementation of an ordered list
 * 
 *  Author: Ryan Sakurai
 */

#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;


typedef struct Node {
    T data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct OrderedList {
    Node *sentinel;
    unsigned size;
    bool (*move_past)(void *a, void *b);
} OrderedList;

typedef struct Iterator {
    OrderedList *list;
    Node *current_item;
} Iterator;


/**
 * Initializes the list
 * 
 * Parameters
 * - OrderedList *list
 * - bool (*move_past)(void *a, void *b): function used to sort the list (true if a must be moved past b)
 * 
 * Returns: void
 */
void init(OrderedList *list, bool (*move_past)(void *a, void *b));


/**
 * Destroys the list
 * 
 * Parameters
 * - OrderedList *list
 * 
 * Returns: void
 */
void destroy(OrderedList *list);


/**
 * Pushes an item to the list, following its order
 * 
 * Parameters
 * - OrderedList *list
 * - T data: data to be pushed to the list
 * 
 * Returns: void
 */
void push(OrderedList *list, T data);


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
bool pop_first(OrderedList *list, T *output);


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
bool pop_last(OrderedList *list, T *output);


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
bool get_first(OrderedList list, T *output);


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
bool get_last(OrderedList list, T *output);


/**
 * Returns the size of the list
 * 
 * Parameters
 * - OrderedList list
 * 
 * Returns: unsigned
 * - The size of the list
 */
unsigned get_size(OrderedList list);


/**
 * Returns if the list is empty
 * 
 * Parameters
 * - OrderedList list
 * 
 * Returns: bool
 * - If the list is empty
 */
bool is_empty(OrderedList list);


/**
 * Initializes the iterator in a list
 * 
 * Parameters
 * - Iterator *iter
 * - OrderedList *list: list the iterator will point to
 * 
 * Returns: bool
 * - True if it was possible to initialize it
 * - False if the list is empty and it wasn't possible
 */
bool iter_init(Iterator *iter, OrderedList *list);


/**
 * Moves the iterator to the next item in the list
 * 
 * Parameters
 * - Iterator *iter
 * 
 * Returns: bool
 * - True if it was possible
 * - False if the end of the list was reached and it wasn't possible
 */
bool iter_next(Iterator *iter);


/**
 * Stores the item currently being pointed by the iterator in a variable
 * 
 * Parameters
 * - Iterator iter
 * - T *output - variable where the item is going to be stored
 * 
 * Returns: bool
 * - True, if it was possible to get the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool get_current_item(Iterator iter, T *output);


/**
 * Pops and stores the item currently being pointed by the iterator in a variable
 * 
 * Parameters
 * - Iterator *iter
 * - T *output: variable where the item is going to be stored
 * 
 * Returns: bool
 * - True, if it was possible to pop the item
 * - False, if the iterator isn't pointing to an item and it wasn't possible
 */
bool pop_current_item(Iterator *iter, T *output);


/**
 * Moves the iterator to a certain item, if it's possible to find it
 * 
 * Parameters
 * - OrderedList *iter
 * - bool (*equals)(void *a, void *b): function used to find the item
 * - T key: key to be searched for
 * 
 * Returns: bool
 * - If it was possible to find it
 */
bool search(Iterator *iter, bool (*equals)(void *a, void *b), T key);


#endif
