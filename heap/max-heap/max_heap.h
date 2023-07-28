/**
 *  Array implementation of a max heap (priority queue)
 * 
 *  Author: Ryan Sakurai
 */

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct MaxHeap {
    T *array;
    int (*compare)(T a, T b);
    unsigned allocation;
    unsigned size;
} MaxHeap;

/**
 * Initializes the heap
 * 
 * Parameters
 * - MaxHeap *heap
 * - int (*compare)(T a, T b): function used to compare items (positive if a is greater, 0 if equal and negative if b is greater)
 * 
 * Returns: void
 */
void maxh_init(MaxHeap *heap, int (*compare)(T a, T b));

/**
 * Destroys the heap
 * 
 * Parameters
 * - MaxHeap *heap
 * 
 * Returns: void
 */
void maxh_destroy(MaxHeap *heap);

/**
 * Pushes an item to the heap
 * 
 * Parameters
 * - MaxHeap *heap
 * - T data: data to be pushed to the heap
 * 
 * Returns: void
 */
void maxh_push(MaxHeap *heap, T data);

/**
 * Pops the maximum element of the heap and stores it in a variable
 * 
 * Parameters
 * - MaxHeap *heap
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool maxh_pop(MaxHeap *heap, T *output);

/**
 * Stores the maximum item of the heap in a variable
 * 
 * Parameters
 * - MaxHeap heap
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool maxh_get_max(MaxHeap heap, T *output);

/**
 * Returns the size of the heap
 * 
 * Parameters
 * - MaxHeap heap
 * 
 * Returns: unsigned
 * - The size of the heap
 */
unsigned maxh_get_size(MaxHeap heap);

/**
 * Returns if the heap is empty
 * 
 * Parameters
 * - MaxHeap heap
 * 
 * Returns: bool
 * - If the heap is empty
 */
bool maxh_is_empty(MaxHeap heap);

#endif
