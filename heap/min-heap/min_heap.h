/**
 *  Array implementation of a min heap (priority queue)
 * 
 *  Author: Ryan Sakurai
 */

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct MinHeap {
    T *array;
    int (*compare)(T a, T b);
    unsigned allocation;
    unsigned size;
} MinHeap;

/**
 * Initializes the heap
 * 
 * Parameters
 * - MinHeap *heap
 * - int (*compare)(T a, T b): function used to compare items (positive if a is greater, 0 if equal and negative if b is greater)
 * 
 * Returns: void
 */
void minh_init(MinHeap *heap, int (*compare)(T a, T b));

/**
 * Destroys the heap
 * 
 * Parameters
 * - MinHeap *heap
 * 
 * Returns: void
 */
void minh_destroy(MinHeap *heap);

/**
 * Pushes an item to the heap
 * 
 * Parameters
 * - MinHeap *heap
 * - T data: data to be pushed to the heap
 * 
 * Returns: void
 */
void minh_push(MinHeap *heap, T data);

/**
 * Pops the minimum element of the heap and stores it in a variable
 * 
 * Parameters
 * - MinHeap *heap
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool minh_pop(MinHeap *heap, T *output);

/**
 * Stores the minimum item of the heap in a variable
 * 
 * Parameters
 * - MinHeap heap
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool minh_get_min(MinHeap heap, T *output);

/**
 * Returns the size of the heap
 * 
 * Parameters
 * - MinHeap heap
 * 
 * Returns: unsigned
 * - The size of the heap
 */
unsigned minh_get_size(MinHeap heap);

/**
 * Returns if the heap is empty
 * 
 * Parameters
 * - MinHeap heap
 * 
 * Returns: bool
 * - If the heap is empty
 */
bool minh_is_empty(MinHeap heap);

#endif
