/**
 *  Linked implementation of an ordered list
 * 
 *  Author: Ryan Sakurai
 */

#include "ordered_list.h"

bool __end_reached(OLIterator iter) {
    return iter.current_item->next == iter.list->sentinel;
}

bool __is_in_range(OLIterator iter) {
    return iter.current_item != iter.list->sentinel;
}

void ol_init(OrderedList *list, int (*compare)(T a, T b)) {
    list->sentinel = malloc(sizeof(OLNode));
    list->sentinel->prev = list->sentinel->next = list->sentinel;
    list->size = 0;
    list->compare = compare;
}

void ol_destroy(OrderedList *list) {
    while(!ol_is_empty(*list))
        ol_pop_first(list, NULL);
    
    free(list->sentinel);
    list->sentinel = NULL;
    list->compare = NULL;
}

void ol_push(OrderedList *list, T data) {
    OLNode *new = malloc(sizeof(OLNode));
    new->data = data;

    OLIterator iter;
    if(ol_iter_init(&iter, list)) {
        while((*list->compare)(new->data, iter.current_item->data) > 0 && ol_iter_next(&iter));
        if(__end_reached(iter) && (*list->compare)(new->data, iter.current_item->data) > 0) {
            // place after current_item
            new->prev = iter.current_item;
            new->next = iter.current_item->next;
        }
        else {
            // place before current_item
            new->prev = iter.current_item->prev;
            new->next = iter.current_item;
        }
    }
    else {
        new->next = new->prev = list->sentinel;
    }

    new->next->prev = new->prev->next = new;
    list->size++;
}

bool ol_pop_first(OrderedList *list, T *output) {
    if(ol_is_empty(*list))
        return false;

    OLNode *old = list->sentinel->next;
    if(output)
        *output = old->data;

    list->sentinel->next = old->next;
    list->sentinel->next->prev = list->sentinel;
    free(old);
    list->size--;

    return true;
}

bool ol_pop_last(OrderedList *list, T *output) {
    if(ol_is_empty(*list))
        return false;

    OLNode *old = list->sentinel->prev;
    if(output)
        *output = old->data;

    list->sentinel->prev = old->prev;
    list->sentinel->prev->next = list->sentinel;
    free(old);
    list->size--;

    return true;
}

bool ol_get_first(OrderedList list, T *output) {
    if(ol_is_empty(list))
        return false;

    if(output)
        *output = list.sentinel->next->data;
    return true;
}

bool ol_get_last(OrderedList list, T *output) {
    if(ol_is_empty(list))
        return false;

    if(output)
        *output = list.sentinel->prev->data;
    return true;
}

unsigned ol_get_size(OrderedList list) {
    return list.size;
}

bool ol_is_empty(OrderedList list) {
    return list.size <= 0;
}

bool ol_iter_init(OLIterator *iter, OrderedList *list) {
    if(ol_is_empty(*list))
        return false;

    iter->list = list;
    iter->current_item = list->sentinel->next;
    return true;
}

bool ol_iter_next(OLIterator *iter) {
    if(__end_reached(*iter))
        return false;

    iter->current_item = iter->current_item->next;
    return true;
}

bool ol_get_current_item(OLIterator iter, T *output) {
    if(!__is_in_range(iter))
        return false;

    if(output)
        *output = iter.current_item->data;
    return true;
}

bool ol_pop_current_item(OLIterator *iter, T *output) {
    if(!__is_in_range(*iter))
        return false;

    OLNode *old = iter->current_item;
    if(output)
        *output = old->data;

    old->prev->next = old->next;
    old->next->prev = old->prev;
    iter->current_item = iter->current_item->next;
    free(old);
    iter->list->size--;

    return true;
}
