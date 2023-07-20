#ifndef __STACK_H__
#define __STACK_H__

#include "glist.h"

typedef GList Stack;

Stack stack_create();

void stack_destroy(Stack stack, DestroyFunction destroy);

int stack_empty(Stack stack);

void *stack_top(Stack stack);

Stack stack_push(Stack stack, CopyFunction copy, void *data);

Stack stack_pop(Stack stack, DestroyFunction destroy);

void stack_print(Stack stack, VisitFunction visit);

#endif /* __STACK_H__*/