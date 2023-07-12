#include "dlist.h"

#include <assert.h>
#include <stdlib.h>

DList *dlist_create() {
  DList *list = malloc(sizeof(DList));
  assert(list != NULL);
  list->first = NULL;
  list->last = NULL;
  return list;
}

void dlist_destroy(DList * list) {
  DNode *temp = list->first;
  DNode *nodeToDelete;

  while (temp != NULL) {
    nodeToDelete = temp;
    temp = temp->next;
    free(nodeToDelete);
  }

  free(list);
}

int dlist_empty(DList * list) {
  return list->first == NULL && list->last == NULL;
}

void dlist_add_first(DList * list, int data) {
  DNode *newNode = malloc(sizeof(DNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = list->first;


  if (dlist_empty(list)) {
    list->last = newNode;
  } else {
    list->first->prev = newNode;
  }

  list->first = newNode;
}

void dlist_add_last(DList * list, int data) {
  DNode *newNode = malloc(sizeof(DNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = list->last;

  if (dlist_empty(list)) {
    list->first = newNode;
  } else {
    list->last->next = newNode;
  }

  list->last = newNode;
}

void dlist_traverse(DList * list, DListTraverseOrder order, VisitFunction visit) {
  DNode *node;
  switch (order) {
  case DLIST_TRAVERSE_FORWARD:
    node = list->first;
    for (; node != NULL; node = node->next) {
      visit(node->data);
    }
    break;
  case DLIST_TRAVERSE_BACKWARD:
    node = list->last;
    for (; node != NULL; node = node->prev) {
      visit(node->data);
    }
    break;
  }
}
