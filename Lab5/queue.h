#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

/* Types for the queue elements */
typedef int elem_t;

/* Definition of data type queue */
typedef struct node_t *node;
typedef struct queue_t *queue;

/* CONTRUCTORS */
queue queue_empty(void);
/*
 * DESC: Creates an empty queue.
 * PRE: {true}
 * USE: queue q = queue_empty();
 * POS: {queue_is_empty(q)}
 */

queue queue_enqueue(queue q, elem_t elem);
/*
 * DESC: Adds [elem] to the queue.
 * PRE: {queue_size(q) == N}
 * USE: q = queue_enqueue(q, elem);
 * POS: {queue_size(q) == N+1}
 */

/* OPERATIONS */
size_t queue_size(queue q);
/*
 * DESC: Returns the number of elements contained in the queue.
 * PRE: {q --> q}
 * USE: n = queue_size(q);
 * POS: {q --> q /\ n >= 0}
 */

queue queue_dequeue(queue q);
/*
 * DESC: Removes a element of the queue.
 * PRE: {queue_size(q) == N}
 * USE: q = queue_dequeue(q);
 * POS: {queue_size(q) == N-1 || queue_size(q) == 0}
 */

elem_t queue_first(queue q);
/*
 * DESC: Returns the first element of the queue.
 * PRE: {queue_size(q) == N /\ queue_is_empty(q) == false}
 * USE: e = queue_first(q);
 * POS: {queue_size(q) == N}
 */

elem_t queue_last(queue q);
/*
 * DESC: Returns the last element of the queue.
 * PRE: {queue_size(q) == N /\ queue_is_empty(q) == false}
 * USE: e = queue_last(q);
 * POS: {queue_size(q) == N}
 */

bool queue_is_empty(queue q);
/*
 * DESC: Indicates if there are no elements in the queue 'q'.
 * PRE: {q --> q}
 * USE: b = queue_is_empty(q);
 * POS: {b == (queue_size(q) == 0)}
 */

void queue_print(queue q);
/*
 * NOTE: This operation is not O(1).
 * DESC: Print all the elements of the queue 'q'.
 * PRE: {q --> q}
 * USE: queue_print(q);
 * POS: {true}
 */

queue queue_free(queue q);
/*
 * NOTE: This operation is not O(1).
 * DESC: Destroy the queue 'q' by freeing all the allocated resources.
 * PRE: {q --> q}
 * USE: q = queue_free(q);
 * POS: {q == NULL}
 */

#endif