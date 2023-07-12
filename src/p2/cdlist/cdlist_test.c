#include "cdlist.h"

#include <stdio.h>

static void print_integer(int n) {
  printf("%d ", n);
}

int main() {
  CDList *list = cdlist_create();

  cdlist_add_first(list, 2);
  cdlist_add_first(list, 1);
  cdlist_add_last(list, 3);
  cdlist_add_last(list, 4);

  printf("Forward...\n");
  cdlist_traverse(list, CDLIST_TRAVERSE_FORWARD, print_integer);
  puts("");

  printf("Backward...\n");
  cdlist_traverse(list, CDLIST_TRAVERSE_BACKWARD, print_integer);
  puts("");

  cdlist_destroy(list);

  return 0;
}
