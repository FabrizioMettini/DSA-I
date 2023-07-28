#include "bstree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define N_NUMS 6

static int *copy_integer_pointer(int *n) {
  int *m = malloc(sizeof(int));
  *m = *n;
  return m;
}

static int compare_integer_pointer(int *n, int *m) {
  return *n == *m ? 0 : *n > *m ? 1 : -1;
}

static void destroy_integer_pointer(int *n) {
  free(n);
}

static void print_integer_pointer(int *n, __attribute__((unused)) void *extra) {
  printf("%d ", *n);
}

int main() {
  int numbers[N_NUMS] = {5, 3, 8, 7, 4, 1};

  BSTree tree = bstree_create();

  for (int i = 0; i < N_NUMS; i++) {
    tree = bstree_insert(tree, &numbers[i], (CopyFunction) copy_integer_pointer, 
                         (CompareFunction) compare_integer_pointer);  
  }

  puts("INORDER:");
  bstree_traverse_extra(tree, BSTREE_TRAVERSE_IN, 
                        (VisitExtraFunction) print_integer_pointer, NULL);
  puts("");

  assert(compare_integer_pointer(bstree_kth_smallest(tree, 3), &numbers[0]) == 0);

  tree = bstree_delete(tree, &numbers[0], 
                       (CompareFunction) compare_integer_pointer, 
                       (DestroyFunction) destroy_integer_pointer);

  puts("INORDER: (after deleting 5)");
  bstree_traverse_extra(tree, BSTREE_TRAVERSE_IN, 
                        (VisitExtraFunction) print_integer_pointer, NULL);
  puts("");

  assert(bstree_validate(tree, (CompareFunction) compare_integer_pointer));

  bstree_destroy(tree, (DestroyFunction) destroy_integer_pointer);

  return 0;
}
