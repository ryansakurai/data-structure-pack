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


typedef struct Node {
    T data;
    struct Node *below;
} Node;

typedef struct Stack {
    Node *top;
    unsigned size;
} Stack;


/**
 * Initializes the stack
 * 
 * Parameters
 * - Stack *stack
 * 
 * Returns: void
 */
void init(Stack *stack);


/**
 * Destroys the stack
 * 
 * Parameters
 * - Stack *stack
 * 
 * Returns: void
 */
void destroy(Stack *stack);


/**
 * Pushes an item to the list
 * 
 * Parameters
 * - Stack *stack
 * - T data: item to be pushed
 * 
 * Returns: void
 */
void push(Stack *stack, T data);


/**
 * Pops an item and stores it in a variable
 * 
 * Parameters
 * - Stack *stack
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool pop(Stack *stack, T *output);


/**
 * Stores the top item of the stack in a variable
 * 
 * Parameters
 * - Stack stack
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - True if it was possible to get the item
 * - False if the stack is empty and it wasn't possible
 */
bool get_top(Stack stack, T *output);


/**
 * Returns the size of the stack
 * 
 * Parameters
 * - Stack stack
 * 
 * Returns: unsigned
 * - The size of the stack
 */
unsigned get_size(Stack stack);


/**
 * Returns if the stack is empty
 * 
 * Parameters
 * - Stack stack
 * 
 * Returns: bool
 * - If the stack is empty
 */
bool is_empty(Stack stack);


#endif
