#include "slists.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void print_integer(int data) {
  printf("%d ", data);
}

int main() {
  // SLISTS_CREATE
  SList list = slists_create();

  // SLISTS_ADD_FIRST
  slists_add_first(list, 2);
  slists_add_first(list, 1);

  // SLISTS_ADD_LAST
  slists_add_last(list, 3);

  // SLISTS_TRAVERSE
  slists_traverse(list, print_integer);
  puts("");

  // SLISTS_DESTROY
  slists_destroy(list);

  return 0;
}
