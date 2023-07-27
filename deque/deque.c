/**
 *  Linked implementation of a deque (double-ended queue)
 * 
 *  Author: Ryan Sakurai
 */

#include "deque.h"


void d_init(Deque *deque) {
    deque->sentinel = malloc(sizeof(DNode));
    deque->sentinel->prev = deque->sentinel->next = deque->sentinel;
    deque->size = 0;
}


void d_destroy(Deque *deque) {
    while(d_pop_first(deque, NULL));
    free(deque->sentinel);
    deque->sentinel = NULL;
}


void d_push_first(Deque *deque, T data) {
    DNode *new = malloc(sizeof(DNode));
    new->data = data;
    new->prev = deque->sentinel;
    new->next = deque->sentinel->next;
    new->prev->next = new->next->prev = new;

    deque->size++;
}


void d_push_last(Deque *deque, T data) {
    DNode *new = malloc(sizeof(DNode));
    new->data = data;
    new->prev = deque->sentinel->prev;
    new->next = deque->sentinel;
    new->prev->next = new->next->prev = new;

    deque->size++;
}


bool d_pop_first(Deque *deque, T *output) {
    if(d_is_empty(*deque))
        return false;

    DNode *old = deque->sentinel->next;
    if(output)
        *output = old->data;

    old->next->prev = old->prev;
    old->prev->next = old->next;
    free(old);
    deque->size--;
    
    return true;
}


bool d_pop_last(Deque *deque, T *output) {
    if(d_is_empty(*deque))
        return false;

    DNode *old = deque->sentinel->prev;
    if(output)
        *output = old->data;

    old->next->prev = old->prev;
    old->prev->next = old->next;
    free(old);
    deque->size--;
    
    return true;
}


bool d_get_first(Deque deque, T *output) {
    if(d_is_empty(deque))
        return false;

    if(output)
        *output = deque.sentinel->next->data;
    return true;
}


bool d_get_last(Deque deque, T *output) {
    if(d_is_empty(deque))
        return false;

    if(output)
        *output = deque.sentinel->prev->data;
    return true;
}


unsigned d_get_size(Deque deque) {
    return deque.size;
}


bool d_is_empty(Deque deque) {
    return d_get_size(deque) <= 0;
}
