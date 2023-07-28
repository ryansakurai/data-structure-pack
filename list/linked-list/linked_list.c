/**
 *  Linked implementation of a list
 * 
 *  Author: Ryan Sakurai
 */

#include "linked_list.h"

bool __end_reached(LLIterator iter) {
    return iter.current_item->next == iter.list->sentinel;
}

bool __is_in_range(LLIterator iter) {
    return iter.current_item != iter.list->sentinel;
}

void ll_init(LinkedList *list) {
    list->sentinel = malloc(sizeof(LLNode));
    list->sentinel->prev = list->sentinel->next = list->sentinel;
    list->size = 0;
}

void ll_destroy(LinkedList *list) {
    while(!ll_is_empty(*list))
        ll_pop_first(list, NULL);
    
    free(list->sentinel);
    list->sentinel = NULL;
}

void ll_push_first(LinkedList *list, T data) {
    LLNode *new = malloc(sizeof(LLNode));
    new->data = data;
    new->next = list->sentinel->next;
    new->prev = list->sentinel;
    new->next->prev = new->prev->next = new;
    list->size++;
}

void ll_push_last(LinkedList *list, T data) {
    LLNode *new = malloc(sizeof(LLNode));
    new->data = data;
    new->next = list->sentinel;
    new->prev = list->sentinel->prev;
    new->next->prev = new->prev->next = new;
    list->size++;
}

bool ll_pop_first(LinkedList *list, T *output) {
    if(ll_is_empty(*list))
        return false;

    LLNode *old = list->sentinel->next;
    if(output)
        *output = old->data;

    list->sentinel->next = old->next;
    list->sentinel->next->prev = list->sentinel;
    free(old);
    list->size--;

    return true;
}

bool ll_pop_last(LinkedList *list, T *output) {
    if(ll_is_empty(*list))
        return false;

    LLNode *old = list->sentinel->prev;
    if(output)
        *output = old->data;

    list->sentinel->prev = old->prev;
    list->sentinel->prev->next = list->sentinel;
    free(old);
    list->size--;

    return true;
}

bool ll_get_first(LinkedList list, T *output) {
    if(ll_is_empty(list))
        return false;

    if(output)
        *output = list.sentinel->next->data;
    return true;
}

bool ll_get_last(LinkedList list, T *output) {
    if(ll_is_empty(list))
        return false;

    if(output)
        *output = list.sentinel->prev->data;
    return true;
}

unsigned ll_get_size(LinkedList list) {
    return list.size;
}

bool ll_is_empty(LinkedList list) {
    return list.size <= 0;
}

bool ll_iter_init(LLIterator *iter, LinkedList *list) {
    if(ll_is_empty(*list))
        return false;

    iter->list = list;
    iter->current_item = list->sentinel->next;
    return true;
}

bool ll_iter_next(LLIterator *iter) {
    if(__end_reached(*iter))
        return false;

    iter->current_item = iter->current_item->next;
    return true;
}

bool ll_get_current_item(LLIterator iter, T *output) {
    if(!__is_in_range(iter))
        return false;

    if(output)
        *output = iter.current_item->data;
    return true;
}

bool ll_push_before_current_item(LLIterator *iter, T data) {
    if(!__is_in_range(*iter))
        return false;

    LLNode *new = malloc(sizeof(LLNode));
    new->data = data;
    new->next = iter->current_item;
    new->prev = iter->current_item->prev;
    new->next->prev = new->prev->next = new;
    return true;
}

bool ll_push_after_current_item(LLIterator *iter, T data) {
    if(!__is_in_range(*iter))
        return false;

    LLNode *new = malloc(sizeof(LLNode));
    new->data = data;
    new->next = iter->current_item->next;
    new->prev = iter->current_item;
    new->next->prev = new->prev->next = new;
    return true;
}

bool ll_pop_current_item(LLIterator *iter, T *output) {
    if(!__is_in_range(*iter))
        return false;

    LLNode *old = iter->current_item;
    if(output)
        *output = old->data;

    old->prev->next = old->next;
    old->next->prev = old->prev;
    iter->current_item = iter->current_item->next;
    free(old);
    iter->list->size--;

    return true;
}
