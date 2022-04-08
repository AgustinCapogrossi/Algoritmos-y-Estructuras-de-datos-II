#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include <assert.h>

struct node_t {
  elem_t elem;
  node sig;
};

struct queue_t {
  size_t length;
  node first;
  node last;
};

queue queue_empty(void) {
  queue new = (queue)malloc(sizeof(struct queue_t));
  new->length = 0;
  new->first = NULL;
  new->last = NULL;
  return new;
}

bool queue_is_empty(queue q) {
  if (q != NULL) {
    bool res = (q->first == NULL);
    return res;
  }
  return true;
}

queue queue_enqueue(queue q, elem_t elem) {
  node new = (node)malloc(sizeof(struct node_t));
  new->elem = elem;
  new->sig = NULL;
  if (q->first == NULL) {
    q->first = new;
    q->last = new;
  } else {
    q->last->sig = new;
    q->last = new;
  }
  q->length++;
  return q;
}

size_t queue_size(queue q) {
  if (q != NULL) {

    return q->length;
  }
  return 0;
}

elem_t queue_first(queue q) {
  assert(queue_size(q) > 0);
  return q->first->elem;
}

elem_t queue_last(queue q) {
  assert(queue_size(q) > 0);
  return q->last->elem;
}

queue queue_dequeue(queue q) {
  if (q->first != NULL) {
    node aux = q->first;
    q->first = q->first->sig;
    free(aux);
    q->length--;
  }
  return q;
}

queue queue_free(queue q) {
  if (q == NULL) {
    return q;
  }
  while (q->first != NULL) {
    q = queue_dequeue(q);
  }
  free(q);
  q = NULL;
  return q;
}

void queue_print(queue q) {
  if (q != NULL) {
    node aux = q->first;
    printf("\tThe queue is: { ");
    while (aux != NULL) {
      printf("%d ", aux->elem);
      aux = aux->sig;
    }
    printf("}\n");
  }
}