#include "stack.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Stack *Stack;

Stack stack_create(int capacity) {
  Stack stack = malloc(sizeof(struct _Stack));
  assert(stack != NULL);
  stack->arr = int_array_create(capacity);
  stack->last = -1;
  return stack;
}

void stack_destroy(Stack stack) {
  int_array_destroy(stack->arr);
  free(stack);
}

int stack_empty(Stack stack) {
  return stack->last == -1;
}

int stack_top(Stack stack) {
  return int_array_read(stack->arr, stack->last);
}

int stack_full(Stack stack) {
  return stack->last == stack->arr->capacity - 1;
}

void stack_push(Stack stack, int data) {
  if (stack_full(stack)) {
    int_array_resize(stack->arr, stack->arr->capacity * 2);
  }

  int_array_write(stack->arr, stack->last + 1, data);
  stack->last = stack->last + 1;
}

void stack_pop(Stack stack) {
  if (!stack_empty(stack)) {
    int_array_delete(stack->arr, stack->last);
    stack->last = stack->last - 1;
  }
}

void stack_print(Stack stack) {
  for (int i = stack->last; i >= 0; i--) {
    printf("%d ", int_array_read(stack->arr, i));
  }
  puts("");
}