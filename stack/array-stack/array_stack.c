/**
 *  Array implementation of a stack
 * 
 *  Author: Ryan Sakurai
 */

#include "array_stack.h"

#define MIN_ALLOC 1

void __set_size(ArrayStack *stack, unsigned size) {
    stack->size = size;

    while(size > stack->allocation)
        stack->allocation *= 2;
    while(size <= stack->allocation/4 && stack->allocation/2 >= MIN_ALLOC)
        stack->allocation /= 2;

    stack->array = realloc(stack->array, stack->allocation * sizeof(T));
}

void as_init(ArrayStack *stack) {
    stack->allocation = MIN_ALLOC;
    stack->array = malloc(stack->allocation * sizeof(T));
    stack->size = 0;
}

void as_destroy(ArrayStack *stack) {
    free(stack->array);
    stack->array = NULL;
    stack->allocation = 0;
    stack->size = 0;
}

void as_push(ArrayStack *stack, T data) {
    __set_size(stack, stack->size+1);
    stack->array[stack->size-1] = data;
}

bool as_pop(ArrayStack *stack, T *output) {
    if(as_is_empty(*stack))
        return false;

    if(output)
        *output = stack->array[stack->size - 1];
    __set_size(stack, stack->size-1);
    return true;
}

bool as_get_top(ArrayStack stack, T *output) {
    if(as_is_empty(stack))
        return false;

    if(output)
        *output = stack.array[stack.size - 1];
    return true;
}

unsigned as_get_size(ArrayStack stack) {
    return stack.size;
}

bool as_is_empty(ArrayStack stack) {
    return as_get_size(stack) <= 0;
}
