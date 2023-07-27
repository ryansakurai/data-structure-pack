/**
 *  Array implementation of a stack
 * 
 *  Author: Ryan Sakurai
 */

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct ArrayStack {
    T *array;
    unsigned size;
    unsigned allocation;
} ArrayStack;

/**
 * Initializes the stack
 * 
 * Parameters
 * - ArrayStack *stack
 * 
 * Returns: void
 */
void as_init(ArrayStack *stack);

/**
 * Destroys the stack
 * 
 * Parameters
 * - ArrayStack *stack
 * 
 * Returns: void
 */
void as_destroy(ArrayStack *stack);

/**
 * Pushes an item to the stack
 * 
 * Parameters
 * - ArrayStack *stack
 * - T data: item to be pushed
 * 
 * Returns: void
 */
void as_push(ArrayStack *stack, T data);

/**
 * Pops the top item of the stack and stores it in a variable
 * 
 * Parameters
 * - ArrayStack *stack
 * - T *output: variable where the item will be stored (can be NULL)
 * 
 * Returns: bool
 * - If it was possible to pop the item
 */
bool as_pop(ArrayStack *stack, T *output);

/**
 * Stores the top item of the stack in a variable
 * 
 * Parameters
 * - ArrayStack stack
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - True if it was possible to get the item
 * - False if the stack is empty and it wasn't possible
 */
bool as_get_top(ArrayStack stack, T *output);

/**
 * Returns the size of the stack
 * 
 * Parameters
 * - ArrayStack stack
 * 
 * Returns: unsigned
 * - The size of the stack
 */
unsigned as_get_size(ArrayStack stack);

/**
 * Returns if the stack is empty
 * 
 * Parameters
 * - ArrayStack stack
 * 
 * Returns: bool
 * - If the stack is empty
 */
bool as_is_empty(ArrayStack stack);

#endif
