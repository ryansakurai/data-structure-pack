/**
 *  Linked implementation of a deque (double-ended queue)
 * 
 *  Author: Ryan Sakurai
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct DNode {
    T data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct Deque {
    DNode *sentinel;
    unsigned size;
} Deque;

/**
 * Initializes the deque
 * 
 * Parameters
 * - Deque *deque
 * 
 * Returns: void
 */
void d_init(Deque *deque);

/**
 * Destroys the deque
 * 
 * Parameters
 * - Deque *deque
 * 
 * Returns: void
 */
void d_destroy(Deque *deque);

/**
 * Pushes an item to the first position of the deque
 * 
 * Parameters
 * - Deque *deque
 * - T data: data to be pushed to the deque
 * 
 * Returns: void
 */
void d_push_first(Deque *deque, T data);

/**
 * Pushes an item to the last position of the deque
 * 
 * Parameters
 * - Deque *deque
 * - T data: data to be pushed to the deque
 * 
 * Returns: void
 */
void d_push_last(Deque *deque, T data);

/**
 * Pops the first item of the deque and stores it in a variable
 * 
 * Parameters
 * - Deque *deque
 * - T *output: variable where the popped item will be stored (can be NULL)
 * 
 * Returns: bool
 * - If it was possible to pop the item
 */
bool d_pop_first(Deque *deque, T *output);

/**
 * Pops the last item of the deque and stores it in a variable
 * 
 * Parameters
 * - Deque *deque
 * - T *output: variable where the popped item will be stored (can be NULL)
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool d_pop_last(Deque *deque, T *output);

/**
 * Stores the first item of the deque in a variable
 * 
 * Parameters
 * - Deque deque
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool d_get_first(Deque deque, T *output);

/**
 * Stores the last item of the deque in a variable
 * 
 * Parameters
 * - Deque deque
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool d_get_last(Deque deque, T *output);

/**
 * Returns the size of the deque
 * 
 * Parameters
 * - Deque deque
 * 
 * Returns: unsigned
 * - The size of the deque
 */
unsigned d_get_size(Deque deque);

/**
 * Returns if the deque is empty or not
 * 
 * Parameters
 * - Deque deque
 * 
 * Returns: bool
 * - If the deque is empty
 */
bool d_is_empty(Deque deque);

#endif
