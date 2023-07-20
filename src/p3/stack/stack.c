#include "stack.h"

#include <stddef.h>

Stack stack_create() {
  return glist_create();
}

void stack_destroy(Stack stack, DestroyFunction destroy) {
  glist_destroy(stack, destroy);
}

int stack_empty(Stack stack) {
  return glist_empty(stack);
}

void *stack_top(Stack stack) {
  if (stack_empty(stack)) {
    return NULL;
  }

  return stack->data;
}

Stack stack_push(Stack stack, CopyFunction copy, void *data) {
  return glist_add_first(stack, data, copy);
}

Stack stack_pop(Stack stack, DestroyFunction destroy) {
  if (stack_empty(stack)) {
    return NULL;
  }

  destroy(stack->data);
  return stack->next;
}

void stack_print(Stack stack, VisitFunction visit) {
  glist_traverse(stack, visit);
}
