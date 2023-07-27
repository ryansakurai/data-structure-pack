/**
 *  Linked implementation of a stack
 * 
 *  Author: Ryan Sakurai
 */

#include "linked_stack.h"

void ls_init(LinkedStack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

void ls_destroy(LinkedStack *stack) {
    while(!ls_is_empty(*stack))
        ls_pop(stack, NULL);
}

void ls_push(LinkedStack *stack, T data) {
    LSNode *new = malloc(sizeof(LSNode));
    new->data = data;
    new->below = stack->top;
    stack->top = new;
    stack->size++;
}

bool ls_pop(LinkedStack *stack, T *output) {
    if(ls_is_empty(*stack))
        return false;

    LSNode *old = stack->top;
    if(output)
        *output = stack->top->data;

    stack->top = stack->top->below;
    free(old);

    return true;
}

bool ls_get_top(LinkedStack stack, T *output) {
    if(ls_is_empty(stack))
        return false;

    if(output)
        *output = stack.top->data;
    return true;
}

unsigned ls_get_size(LinkedStack stack) {
    return stack.size;
}

bool ls_is_empty(LinkedStack stack) {
    return ls_get_size(stack) <= 0;
}
