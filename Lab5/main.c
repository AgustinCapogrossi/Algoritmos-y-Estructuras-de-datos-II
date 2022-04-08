#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void on_enqueue(queue q) {
  int elem = 0;
  printf("Please enter an element on the queue: ");
  scanf("%d", &elem);
  q = queue_enqueue(q, elem);
  printf("\tYour element was successfully queued.\n");
}

void on_dequeue(queue q) {
  q = queue_dequeue(q);
  printf("\tYour element was successfully dequeuied.\n");
}

void on_size(queue q) {
  printf("\tThe size of the queue is: %lu\n", queue_size(q));
}

void on_extremes(queue q) {
  if (!queue_is_empty(q)) {
    elem_t first = queue_first(q);
    printf("\tThe first element on the queue is: %d\n", first);
    elem_t last = queue_last(q);
    printf("\tThe last element on the queue is: %d\n", last);
  }
}

void on_is_empty(queue q) {
  queue_is_empty(q) ? printf("\tThe queue is empty.\n")
                    : printf("\tThe queue is not empty.\n");
}

void show_status(queue q) {
  printf("\nStatus of the queue: \n");
  on_is_empty(q);
  queue_print(q);
  on_size(q);
  on_extremes(q);
}

char print_menu(void) {

  char option;

  printf("\nChoose what you want to do. Options are:\n"
         "\n"
         "\t**************************************************************\n"
         "\t* e: Enqueue a new element in the queue.                     *\n"
         "\t* d: Dequeue an element.                                     *\n"
         "\t* s: Show the status of the queue.                           *\n"
         "\t* q: Quit.                                                   *\n"
         "\t**************************************************************\n"
         "\nPlease enter your choice: ");

  scanf(" %c", &option);
  return option;
}

int main(void) {
  queue q = queue_empty();
  char option = '\0';
  do {

    option = print_menu();
    switch (option) {
    case 'e':
      on_enqueue(q);
      break;
    case 's':
      show_status(q);
      break;
    case 'd':
      on_dequeue(q);
      break;
    case 'q':
      printf("\tExiting.\n");
      break;
    default:
      printf("Enter an valid option.\n");
      break;
    }

  } while (option != 'q');
  q = queue_free(q);

  return (EXIT_SUCCESS);
}