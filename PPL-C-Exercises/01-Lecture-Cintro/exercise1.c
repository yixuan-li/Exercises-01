#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/*
 * Exercise 1
 * 
 * Implement in list.c the following:
 *  - list_init
 *  - list_push_front
 *  - list_front
 *  - list_node_next
 *  - list_delete
 * (As per the declarations in list.h)
 *
 * Test the executable by running it with a few integers as arguments,
 * e.g.:
 *
 * ./exercise1 5 4 1 28
 */
int main(int argc, char** argv) {
  assert(argc > 1);
  
  list* numbers = list_init();

  // Start at 1 because 0 is the program name
  for (int i = 1; i != argc; ++i) {
    int val = atoi(argv[i]);
    
    list_push_front(numbers, val);
  }
  
  // count
  int count = 0;
  for (node* n = list_front(numbers); n != NULL; n = list_node_next(n)) 
    ++count;
  assert(count == argc-1);
  printf("Successfully read %d integers\n", count);
  
  list_delete(numbers);
}
