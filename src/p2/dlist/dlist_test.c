#include "dlist.h"

#include <stdio.h>

static void print_integer(int n) {
  printf("%d ", n);
}

int main() {
  DList *list = dlist_create();

  dlist_add_first(list, 2);
  dlist_add_first(list, 1);
  dlist_add_last(list, 3);

  printf("Forward...\n");
  dlist_traverse(list, DLIST_TRAVERSE_FORWARD, print_integer);
  puts("");


  printf("Backward...\n");
  dlist_traverse(list, DLIST_TRAVERSE_BACKWARD, print_integer);
  puts("");

  dlist_destroy(list);

  return 0;
}
