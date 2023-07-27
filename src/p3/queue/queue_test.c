#include "queue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

static int *copy_int_ptr(int *ptr_n) {
  int * ptr_m = malloc(sizeof(int));
  *ptr_m = *ptr_n;
  return ptr_m;
}

static void destroy_int_ptr(int *ptr_n) {
  free(ptr_n);
}

static void print_int_ptr(int *ptr_n) {
  printf("%d ", *ptr_n);
}

int main() {
  int a[N] = {1, 2, 3, 4, 5};

  Queue queue = queue_create();

  assert(queue_empty(queue));

  for (int i = 0; i < N; i++)
    queue = queue_push(queue, &a[i], (CopyFunction) copy_int_ptr);
  
  assert(!queue_empty(queue));

  puts("Queue: ");
  queue_print(queue, (VisitFunction) print_int_ptr);
  puts("");

  queue = queue_pop(queue, (DestroyFunction) destroy_int_ptr);
  queue = queue_pop(queue, (DestroyFunction) destroy_int_ptr);

  puts("Queue: (after 2 pops)");
  queue_print(queue, (VisitFunction) print_int_ptr);
  puts("");

  queue_destroy(queue, (DestroyFunction) destroy_int_ptr);
  
  return 0;
}
