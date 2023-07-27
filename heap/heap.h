/**
 *  Array implementation of a heap (priority queue)
 * 
 *  Author: Ryan Sakurai
 */

#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct Heap {
    T *array;
    unsigned allocation;
    unsigned size;
} Heap;

/**
 * Initializes the heap
 * 
 * Parameters
 * - Heap *heap
 * 
 * Returns: void
 */
void h_init(Heap *heap);


/**
 * Destroys the heap
 * 
 * Parameters
 * - Heap *heap
 * 
 * Returns: void
 */
void h_destroy(Heap *heap);


/**
 * Pushes an item to the heap
 * 
 * Parameters
 * - Heap *heap
 * - T data: data to be pushed to the heap
 * 
 * Returns: void
 */
void h_push(Heap *heap, T data);


/**
 * Pops the minimum element of the heap and stores it in a variable
 * 
 * Parameters
 * - Heap *heap
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool h_pop(Heap *heap, T *output);


/**
 * Stores the minimum item of the heap in a variable
 * 
 * Parameters
 * - Heap heap
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool h_get_min(Heap heap, T *output);


/**
 * Returns the size of the heap
 * 
 * Parameters
 * - Heap heap
 * 
 * Returns: unsigned
 * - The size of the heap
 */
unsigned h_get_size(Heap heap);


/**
 * Returns if the heap is empty
 * 
 * Parameters
 * - Heap heap
 * 
 * Returns: bool
 * - If the heap is empty
 */
bool h_is_empty(Heap heap);


#endif
