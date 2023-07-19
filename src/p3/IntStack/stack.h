#ifndef __STACK_H__
#define __STACK_H__

#include "IntArray.h"

struct _Stack {
    IntArray *arr;
    int last;
};

typedef struct _Stack *Stack;

Stack stack_create(int capacity);

void stack_destroy(Stack stack);

int stack_empty(Stack stack);

int stack_top(Stack stack);

void stack_push(Stack stack, int data);

void stack_pop(Stack stack);

void stack_print(Stack stack);

#endif /* __STACK_H__*/