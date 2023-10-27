/**
 *  Array implementation of an ordered list
 * 
 *  Author: Ryan Sakurai
 */

#ifndef ARRAY_ORDERED_LIST_H
#define ARRAY_ORDERED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct ArrayOrderedList {
    T *array;
    unsigned allocation;
    unsigned size;
    int (*compare)(T a, T b);
} ArrayOrderedList;

/**
 * Initializes the list
 * 
 * Parameters
 * - ArrayOrderedList *list
 * - int (*compare)(T a, T b): function used to compare items (positive if a is greater, 0 if equal and negative if b is greater)
 * 
 * Returns: void
 */
void aol_init(ArrayOrderedList *list, int (*compare)(T a, T b));

/**
 * Destroys the list
 * 
 * Parameters
 * - ArrayOrderedList *list
 * 
 * Returns: void
 */
void aol_destroy(ArrayOrderedList *list);

/**
 * Pushes an item to the list, following its order
 * 
 * Parameters
 * - ArrayOrderedList *list
 * - T data: data to be pushed to the list
 * 
 * Returns: void
 */
void aol_push(ArrayOrderedList *list, T data);

/**
 * Removes an item from a specific position
 * 
 * Parameters
 * - ArrayOrderedList *list
 * - unsigned index: index of the item to be removed
 * 
 * Returns: bool
 * - If it was possible to remove the item
 */
bool aol_remove(ArrayOrderedList *list, unsigned index);

/**
 * Stores the item from a specific position in a variable
 * 
 * Parameters
 * - ArrayOrderedList list
 * - unsigned index: index of the item to be gotten
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool aol_get(ArrayOrderedList list, unsigned index, T *output);

/**
 * Returns the size of the list
 * 
 * Parameters
 * - ArrayOrderedList list
 * 
 * Returns: unsigned
 * - The size of the list
 */
unsigned aol_get_size(ArrayOrderedList list);

/**
 * Returns if the list is empty
 * 
 * Parameters
 * - ArrayOrderedList list
 * 
 * Returns: bool
 * - If the list is empty
 */
bool aol_is_empty(ArrayOrderedList list);

#endif
