#include "bheap.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

static int *copy_int_ptr(int *ptr_n) {
  int * ptr_m = malloc(sizeof(int));
  *ptr_m = *ptr_n;
  return ptr_m;
}

static void destroy_int_ptr(int *ptr_n) {
  free(ptr_n);
}

static int compare_int_ptr(int *ptr_n, int *ptr_m) {
  return *ptr_n > *ptr_m;
}

static void print_int_ptr(int *ptr_n) {
  printf("%d ", *ptr_n);
}

int main() {
  int a[N] = {10, 20, 15, 25, 30, 16, 18, 19};

  BHeap bheap = bheap_create(4, (CompareFunction) compare_int_ptr);

  assert(bheap_is_empty(bheap));

  for (int i = 0; i < N; i++) {
    bheap = bheap_insert(bheap, a + i, (CopyFunction) copy_int_ptr);
    printf("n: %d, ", bheap->last);
    printf("capacity: %d, ", bheap->capacity);  
    printf("inserted: %d\n", a[i]);
  }
  
  assert(!bheap_is_empty(bheap));

  puts("BHeap: ");
  bheap_traverse(bheap, (VisitFunction) print_int_ptr);
  puts("");

  bheap = bheap_delete(bheap, (DestroyFunction) destroy_int_ptr);

  puts("BHeap: (after deletion)");
  bheap_traverse(bheap, (VisitFunction) print_int_ptr);
  puts("");

  bheap_destroy(bheap, (DestroyFunction) destroy_int_ptr);
  
  return 0;
}
