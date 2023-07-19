#include "btree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void print_integer(int data) {
  printf("%d ", data);
}

int main() {
  BTree lr = btree_join(2, btree_create(), btree_create());
  BTree l = btree_join(1, btree_create(), lr);
  BTree r = btree_join(4, btree_create(), btree_create());
  BTree root = btree_join(3, l, r);

  btree_traverse(root, BTREE_TRAVERSE_IN, print_integer);
  puts("");

  assert(btree_nnodes(root) == 4);
  
  assert(btree_find(root, 2) == 1);
  assert(btree_find(root, 5) == 0);
  
  assert(btree_nnodes_depth(root, 1) == 2);
  assert(btree_nnodes_depth(root, 2) == 1);
  assert(btree_nnodes_depth(root, 3) == 0);

  assert(btree_depth(root, 2) == 2);
  assert(btree_depth(root, 5) == -1);

  assert(btree_height(root) == 2);
  assert(btree_height(lr) == 0);

  assert(btree_sum(root) == 10);

  btree_destroy(root);

  return 0;
}
