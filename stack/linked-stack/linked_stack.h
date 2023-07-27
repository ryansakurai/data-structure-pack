/**
 *  Linked implementation of a stack
 * 
 *  Author: Ryan Sakurai
 */

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct LSNode {
    T data;
    struct LSNode *below;
} LSNode;

typedef struct LinkedStack {
    LSNode *top;
    unsigned size;
} LinkedStack;

/**
 * Initializes the stack
 * 
 * Parameters
 * - LinkedStack *stack
 * 
 * Returns: void
 */
void ls_init(LinkedStack *stack);

/**
 * Destroys the stack
 * 
 * Parameters
 * - LinkedStack *stack
 * 
 * Returns: void
 */
void ls_destroy(LinkedStack *stack);

/**
 * Pushes an item to the list
 * 
 * Parameters
 * - LinkedStack *stack
 * - T data: item to be pushed
 * 
 * Returns: void
 */
void ls_push(LinkedStack *stack, T data);

/**
 * Pops an item and stores it in a variable
 * 
 * Parameters
 * - LinkedStack *stack
 * - T *output: variable where the item will be stored (can be NULL)
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool ls_pop(LinkedStack *stack, T *output);

/**
 * Stores the top item of the stack in a variable
 * 
 * Parameters
 * - LinkedStack stack
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - True if it was possible to get the item
 * - False if the stack is empty and it wasn't possible
 */
bool ls_get_top(LinkedStack stack, T *output);

/**
 * Returns the size of the stack
 * 
 * Parameters
 * - LinkedStack stack
 * 
 * Returns: unsigned
 * - The size of the stack
 */
unsigned ls_get_size(LinkedStack stack);

/**
 * Returns if the stack is empty
 * 
 * Parameters
 * - LinkedStack stack
 * 
 * Returns: bool
 * - If the stack is empty
 */
bool ls_is_empty(LinkedStack stack);

#endif
