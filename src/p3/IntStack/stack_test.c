#include "stack.h"

#include <assert.h>
#include <stdio.h>

#define STACK_SIZE 5

int main() {
  Stack stack = stack_create(STACK_SIZE);

  assert(stack_empty(stack));

  for (int i = 0; i < STACK_SIZE; i++) {
    stack_push(stack, i + 1);
  }

  assert(!stack_empty(stack));

  stack_print(stack);
  
  assert(stack_top(stack) == 5);
  stack_pop(stack);
  assert(stack_top(stack) == 4);

  stack_destroy(stack);
  
  return 0;
}