/**
 *  Linked implementation of a queue 
 * 
 *  Author: Ryan Sakurai
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct QNode {
    T data;
    struct QNode *prev;
    struct QNode *next;
} QNode;

typedef struct Queue {
    QNode *sentinel;
    unsigned size;
} Queue;

/**
 * Initializes the queue
 * 
 * Parameters
 * - Queue *queue
 * 
 * Returns: void
 */
void q_init(Queue *queue);

/**
 * Destroys the queue
 * 
 * Parameters
 * - Queue *queue
 * 
 * Returns: void
 */
void q_destroy(Queue *queue);

/**
 * Pushes an item to the queue
 * 
 * Parameters
 * - Queue *queue
 * - T data: data to be pushed to the queue
 * 
 * Returns: void
 */
void q_push(Queue *queue, T data);

/**
 * Pops the an item from the queue and stores it in a variable
 * 
 * Parameters
 * - Queue *queue
 * - T *output: variable where the popped item will be stored
 * 
 * Returns: bool
 * - If it was possible to pop an item
 */
bool q_pop(Queue *queue, T *output);

/**
 * Stores the first item of the queue in a variable
 * 
 * Parameters
 * - Queue queue
 * - T *output: variable where the item will be stored
 * 
 * Returns: bool
 * - If it was possible to get the item
 */
bool q_get_first(Queue queue, T *output);

/**
 * Returns the size of the queue
 * 
 * Parameters
 * - Queue queue
 * 
 * Returns: unsigned
 * - The size of the queue
 */
unsigned q_get_size(Queue queue);

/**
 * Returns if the queue is empty
 * 
 * Parameters
 * - Queue queue
 * 
 * Returns: bool
 * - If the queue is empty
 */
bool q_is_empty(Queue queue);

#endif
