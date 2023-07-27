/**
 *  Linked implementation of a queue 
 * 
 *  Author: Ryan Sakurai
 */

#include "queue.h"

void q_init(Queue *queue) {
    queue->sentinel = malloc(sizeof(QNode));
    queue->sentinel->prev = queue->sentinel->next = queue->sentinel;
    queue->size = 0;
}

void q_destroy(Queue *queue) {
    while(!is_empty(*queue))
        pop(queue, NULL);
    
    free(queue->sentinel);
    queue->sentinel = NULL;
}

void q_push(Queue *queue, T data) {
    QNode *new = malloc(sizeof(QNode));
    new->data = data;
    new->prev = queue->sentinel->prev;
    new->next = queue->sentinel;
    new->prev->next = new->next->prev = new;

    queue->size++;
}

bool q_pop(Queue *queue, T *output) {
    if(is_empty(*queue))
        return false;

    QNode *old = queue->sentinel->next;
    if(output)
        *output = old->data;

    old->next->prev = old->prev;
    old->prev->next = old->next;
    free(old);
    
    return true;
}

bool q_get_first(Queue queue, T *output) {
    if(is_empty(queue))
        return false;

    if(output)
        *output = queue.sentinel->next->data;
    return true;
}

unsigned q_get_size(Queue queue) {
    return queue.size;
}

bool q_is_empty(Queue queue) {
    return get_size(queue) <= 0;
}
