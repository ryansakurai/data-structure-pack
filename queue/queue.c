/**
 *  Linked implementation of a queue 
 * 
 *  Author: Ryan Sakurai
 */

#include "queue.h"


void init(Queue *queue) {
    queue->sentinel = malloc(sizeof(Node));
    queue->sentinel->prev = queue->sentinel->next = queue->sentinel;
    queue->size = 0;
}


void destroy(Queue *queue) {
    while(!is_empty(*queue))
        pop(queue, NULL);
    
    free(queue->sentinel);
    queue->sentinel = NULL;
}


void push(Queue *queue, T data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->prev = queue->sentinel->prev;
    new->next = queue->sentinel;
    new->prev->next = new->next->prev = new;

    queue->size++;
}


bool pop(Queue *queue, T *output) {
    if(is_empty(*queue))
        return false;

    Node *old = queue->sentinel->next;
    if(output)
        *output = old->data;

    old->next->prev = old->prev;
    old->prev->next = old->next;
    free(old);
    
    return true;
}


bool get_first(Queue queue, T *output) {
    if(is_empty(queue))
        return false;

    if(output)
        *output = queue.sentinel->next->data;
    return true;
}


unsigned get_size(Queue queue) {
    return queue.size;
}


bool is_empty(Queue queue) {
    return get_size(queue) <= 0;
}
