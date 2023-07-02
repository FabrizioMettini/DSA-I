#include "slist.h"

#include <stdio.h>
#include <stdlib.h>

static void print_integer(int data) {
  printf("%d ", data);
}

int main() {

  SList list = slist_create();

  list = slist_add_first(list, 3);
  list = slist_add_first(list, 2);
  list = slist_add_first(list, 1);
  list = slist_add_last(list, 4);

  slist_traverse(list, print_integer);
  puts("");

  slist_destroy(list);

  return 0;
}
