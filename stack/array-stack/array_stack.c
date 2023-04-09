/**
 *  Array implementation of a stack
 * 
 *  Author: Ryan Sakurai
 */

#include "array_stack.h"


void init(Stack *stack) {
    stack->array_size = 1;
    stack->array = malloc(stack->array_size * sizeof(T));
    stack->first_empty_index = 0;
}


void destroy(Stack *stack) {
    free(stack->array);
    stack->array = NULL;
}


bool is_array_full(Stack stack) {
    return stack.array_size == get_size(stack);
}


void push(Stack *stack, T data) {
    if(is_array_full(*stack)) {
        stack->array_size *= 2;
        stack->array = realloc(stack->array, stack->array_size * sizeof(T));
    }

    stack->array[stack->first_empty_index++] = data;
}


bool is_array_too_big(Stack stack) {
    return stack.array_size > 1 && get_size(stack) <= stack.array_size/4;
}


bool pop(Stack *stack, T *output) {
    if(is_empty(*stack))
        return false;

    if(output)
        *output = stack->array[stack->first_empty_index - 1];
    stack->first_empty_index--;

    if(is_array_too_big(*stack)) {
        stack->array_size /= 2;
        stack->array = realloc(stack->array, stack->array_size * sizeof(T));
    }

    return true;
}


bool get_top(Stack stack, T *output) {
    if(is_empty(stack))
        return false;

    if(output)
        *output = stack.array[stack.first_empty_index - 1];
    return true;
}


unsigned get_size(Stack stack) {
    return stack.first_empty_index;
}


bool is_empty(Stack stack) {
    return get_size(stack) <= 0;
}
