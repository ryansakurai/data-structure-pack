/**
 *  Array implementation of a list
 * 
 *  Author: Ryan Sakurai
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct ArrayList {
    T *array;
    unsigned allocation;
    unsigned size;
} ArrayList;

/**
 * Initializes the list
 * 
 * Parameters
 * - ArrayList *list
 * 
 * Returns: void
 */
void al_init(ArrayList *list);


/**
 * Destroys the list
 * 
 * Parameters
 * - ArrayList *list
 * 
 * Returns: void
 */
void al_destroy(ArrayList *list);


/**
 * Pushes an item to the list
 * 
 * Parameters
 * - ArrayList *list
 * - T data: data to be pushed to the list
 * 
 * Returns: void
 */
void al_push(ArrayList *list, T data);


/**
 * Inserts an item in a specific position
 * 
 * Parameters
 * - ArrayList *list
 * - unsigned index: index where the data will be inserted
 * - T data: data to be pushed to the list
 * 
 * Returns: bool
 * - If it was possible to insert the item
 */
bool al_insert(ArrayList *list, unsigned index, T data);


/**
 * Removes an item from a specific position
 * 
 * Parameters
 * - ArrayList *list
 * - unsigned index: index of the item to be removed
 * 
 * Returns: bool
 * - If it was possible to remove the item
 */
bool al_remove(ArrayList *list, unsigned index);


/**
 * Stores the item from a specific position in a variable
 * 
 * Parameters
 * - ArrayList list
 * - unsigned index: index of the item to be gotten
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool al_get(ArrayList list, unsigned index, T *output);


/**
 * Returns the size of the list
 * 
 * Parameters
 * - ArrayList list
 * 
 * Returns: unsigned
 * - The size of the list
 */
unsigned al_get_size(ArrayList list);


/**
 * Returns if the list is empty
 * 
 * Parameters
 * - ArrayList list
 * 
 * Returns: bool
 * - If the list is empty
 */
bool al_is_empty(ArrayList list);


#endif
