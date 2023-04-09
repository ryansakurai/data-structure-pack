/**
 *  Linked implementation of an ordered list
 * 
 *  Author: Ryan Sakurai
 */

#include "ordered_list.h"


void init(OrderedList *list, bool (*move_past)(void *a, void *b)) {
    list->sentinel = malloc(sizeof(Node));
    list->sentinel->prev = list->sentinel->next = list->sentinel;
    list->size = 0;
    list->move_past = move_past;
}


void destroy(OrderedList *list) {
    while(!is_empty(*list))
        pop_first(list, NULL);
    
    free(list->sentinel);
    list->sentinel = NULL;
}


bool end_reached(Iterator iter) {
    return iter.current_item->next == iter.list->sentinel;
}


void push(OrderedList *list, T data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;

    Iterator iter;
    if(iter_init(&iter, list)) {
        while((*list->move_past)(&new->data, &iter.current_item->data) && iter_next(&iter));

        if(end_reached(iter) && (*list->move_past)(&new->data, &iter.current_item->data)) {
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


bool pop_first(OrderedList *list, T *output) {
    if(is_empty(*list))
        return false;

    Node *old = list->sentinel->next;
    if(output)
        *output = old->data;

    list->sentinel->next = old->next;
    list->sentinel->next->prev = list->sentinel;
    free(old);
    list->size--;

    return true;
}


bool pop_last(OrderedList *list, T *output) {
    if(is_empty(*list))
        return false;

    Node *old = list->sentinel->prev;
    if(output)
        *output = old->data;

    list->sentinel->prev = old->prev;
    list->sentinel->prev->next = list->sentinel;
    free(old);
    list->size--;

    return true;
}


bool get_first(OrderedList list, T *output) {
    if(is_empty(list))
        return false;

    if(output)
        *output = list.sentinel->next->data;
    return true;
}


bool get_last(OrderedList list, T *output) {
    if(is_empty(list))
        return false;

    if(output)
        *output = list.sentinel->prev->data;
    return true;
}


unsigned get_size(OrderedList list) {
    return list.size;
}


bool is_empty(OrderedList list) {
    return list.size <= 0;
}


bool iter_init(Iterator *iter, OrderedList *list) {
    if(is_empty(*list))
        return false;

    iter->list = list;
    iter->current_item = list->sentinel->next;
    return true;
}


bool iter_next(Iterator *iter) {
    if(end_reached(*iter))
        return false;

    iter->current_item = iter->current_item->next;
    return true;
}

bool is_in_range(Iterator iter) {
    return iter.current_item != iter.list->sentinel;
}


bool get_current_item(Iterator iter, T *output) {
    if(!is_in_range(iter))
        return false;

    if(output)
        *output = iter.current_item->data;
    return true;
}


bool pop_current_item(Iterator *iter, T *output) {
    if(!is_in_range(*iter))
        return false;

    Node *old = iter->current_item;
    if(output)
        *output = old->data;

    old->prev->next = old->next;
    old->next->prev = old->prev;
    iter->current_item = iter->current_item->next;
    free(old);
    iter->list->size--;

    return true;
}


bool search(Iterator *iter, bool (*equals)(void *a, void *b), T key) {
    Iterator private_iter;
    if(iter_init(&private_iter, iter->list))
        do {
            if((*equals)(&key, &private_iter.current_item->data)) {
                iter->current_item = private_iter.current_item;
                return true;
            }
        } while(iter_next(&private_iter));

    return false;
}
