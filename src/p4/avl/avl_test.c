#include "avl.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
  AVL avl = avl_create((CopyFunction) copy_integer_pointer, 
                       (CompareFunction) compare_integer_pointer,
                       (DestroyFunction) destroy_integer_pointer);

  for (int i = 0; i < 500; ++i) {
    int i = rand() % 1000;
    avl_insert(avl, &i);
    assert(avl_validate(avl) == 1);
  }

  avl_destroy(avl);

  AVL avl2 = avl_create((CopyFunction) copy_integer_pointer, 
                        (CompareFunction) compare_integer_pointer,
                        (DestroyFunction) destroy_integer_pointer);

  int nums[] = { 10, 20, 15, 25, 30, 16, 18, 19 };
  for (int i = 0; i < 8; ++i) {
    avl_insert(avl2, nums + i);
    printf("Inserting %d. PREORDER: ", nums[i]);
    avl_traverse(avl2, AVL_TRAVERSE_ORDER_PRE, 
                 (VisitExtraFunction) print_integer_pointer, NULL);
    puts("");
  }

  int nums2[] = { -50, -4, 5, 14, 27, 56 };
  for (int i = 0; i < 8; ++i)
    assert(avl_search(avl2, nums + i) == 1);
  for (int i = 0; i < 6; ++i)
    assert(avl_search(avl2, nums2 + i) == 0);

  avl_destroy(avl2);

  puts("Ok");

  return 0;
}