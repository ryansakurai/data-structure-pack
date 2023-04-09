/**
 *  Linked implementation of a stack
 * 
 *  Author: Ryan Sakurai
 */

#include "linked_stack.h"


void init(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}


void destroy(Stack *stack) {
    while(!is_empty(*stack))
        pop(stack, NULL);
}


void push(Stack *stack, T data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->below = stack->top;
    stack->top = new;
    stack->size++;
}


bool pop(Stack *stack, T *output) {
    if(is_empty(*stack))
        return false;

    Node *old = stack->top;
    if(output)
        *output = stack->top->data;

    stack->top = stack->top->below;
    free(old);

    return true;
}


bool get_top(Stack stack, T *output) {
    if(is_empty(stack))
        return false;

    *output = stack.top->data;
    return true;
}


unsigned get_size(Stack stack) {
    return stack.size;
}


bool is_empty(Stack stack) {
    return get_size(stack) <= 0;
}
