#include "contact.h"
#include "stack.h"

#include <assert.h>
#include <stdio.h>

#define NCONTACTS 6

int main() {
  Contact *contacts[NCONTACTS];
  contacts[0] = contact_create("Pepe Argento", "3412695452", 61);
  contacts[1] = contact_create("Moni Argento", "3412684759", 60);
  contacts[2] = contact_create("Coqui Argento", "3415694286", 32);
  contacts[3] = contact_create("Paola Argento", "3416259862", 29);
  contacts[4] = contact_create("Maria Elena Fuseneco", "3416874594", 59);
  contacts[5] = contact_create("Dardo Fuseneco", "3416894526", 64);

  Stack stack = stack_create();

  assert(stack_empty(stack));

  for (int i = 0; i < NCONTACTS; i++) {
    stack = stack_push(stack, (CopyFunction) contact_copy, (Contact *) contacts[i]);
  }

  assert(!stack_empty(stack));

  stack_print(stack, (VisitFunction) contact_print);
  
  assert(contact_compare(stack_top(stack), contacts[5]) == 0);
  stack = stack_pop(stack, (DestroyFunction) contact_destroy);
  assert(contact_compare(stack_top(stack), contacts[4]) == 0);

  for (int i = 0; i < NCONTACTS; i++) {
    contact_destroy(contacts[i]);
  }  
  
  stack_destroy(stack, (DestroyFunction) contact_destroy);
  
  return 0;
}