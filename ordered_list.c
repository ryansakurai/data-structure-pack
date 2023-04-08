/**
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
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    Iterator iter;
    if(iter_init(&iter, list)) {
        while((*list->move_past)(&new_node->data, &iter.current_item->data) && iter_next(&iter));

        if(end_reached(iter) && (*list->move_past)(&new_node->data, &iter.current_item->data)) {
            // places after current_item
            new_node->prev = iter.current_item;
            new_node->next = iter.current_item->next;
            new_node->next->prev = new_node;
            new_node->prev->next = new_node;
        }
        else {
            // places before current_item
            new_node->prev = iter.current_item->prev;
            new_node->next = iter.current_item;
            new_node->next->prev = new_node;
            new_node->prev->next = new_node;
        }
    }
    else {
        new_node->next = new_node->prev = list->sentinel;
        new_node->next->prev = new_node;
        new_node->prev->next = new_node;
    }
    
    list->size++;
}


bool pop_first(OrderedList *list, T *output) {
    if(!is_empty(*list)) {
        Node *popped = list->sentinel->next;
        if(output)
            *output = popped->data;

        list->sentinel->next = popped->next;
        list->sentinel->next->prev = list->sentinel;
        free(popped);
        list->size--;

        return true;
    }
    else {
        return false;
    }
}


bool pop_last(OrderedList *list, T *output) {
    if(!is_empty(*list)) {
        Node *popped = list->sentinel->prev;
        if(output)
            *output = popped->data;

        list->sentinel->prev = popped->prev;
        list->sentinel->prev->next = list->sentinel;
        free(popped);
        list->size--;

        return true;
    }
    else {
        return false;
    }
}


bool get_first(OrderedList list, T *output) {
    if(!is_empty(list)) {
        *output = list.sentinel->next->data;
        return true;
    }
    else {
        return false;
    }
}


bool get_last(OrderedList list, T *output) {
    if(!is_empty(list)) {
        *output = list.sentinel->prev->data;
        return true;
    }
    else {
        return false;
    }
}


unsigned get_size(OrderedList list) {
    return list.size;
}


bool is_empty(OrderedList list) {
    return list.size <= 0;
}


bool iter_init(Iterator *iter, OrderedList *list) {
    if(!is_empty(*list)) {
        iter->list = list;
        iter->current_item = list->sentinel->next;
        return true;
    }
    else {
        return false;
    }
}


bool iter_next(Iterator *iter) {
    if(!end_reached(*iter)) {
        iter->current_item = iter->current_item->next;
        return true;
    }
    else {
        return false;
    }
}

bool is_in_range(Iterator iter) {
    return iter.current_item != iter.list->sentinel;
}


bool get_current_item(Iterator iter, T *output) {
    if(is_in_range(iter)) {
        *output = iter.current_item->data;
        return true;
    }
    else {
        return false;
    }
}


bool pop_current_item(Iterator *iter, T *output) {
    if(is_in_range(*iter)) {
        Node *popped = iter->current_item;
        *output = popped->data;

        popped->prev->next = popped->next;
        popped->next->prev = popped->prev;
        iter->current_item = iter->current_item->next;
        free(popped);
        iter->list->size--;

        return true;
    }
    else {
        return false;
    }
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
