#include "cdlist.h"

#include <assert.h>
#include <stdlib.h>

CDList *cdlist_create() {
  CDList *list = malloc(sizeof(CDList));
  assert(list != NULL);
  list->first = NULL;
  return list;
}

void cdlist_destroy(CDList * list) {
  DNode *temp = list->first;
  DNode *nodeToDelete;

  do {
    nodeToDelete = temp;
    temp = temp->next;
    free(nodeToDelete);
  } while (temp != list->first);

  free(list);
}

int cdlist_empty(CDList * list) {
  return list->first == NULL;
}

void cdlist_add_first(CDList * list, int data) {
  DNode *newNode = malloc(sizeof(DNode));
  assert(newNode != NULL);
  newNode->data = data;

  if (cdlist_empty(list)) {
    newNode->next = newNode;
    newNode->prev = newNode;
  } else {
    newNode->next = list->first;
    newNode->prev = list->first->prev;
    list->first->prev = newNode;

    // when list length 1
    if (list->first->next == list->first) {
      list->first->next = newNode;
    }
  }

  list->first = newNode;
}

void cdlist_add_last(CDList * list, int data) {
  DNode *newNode = malloc(sizeof(DNode));
  assert(newNode != NULL);
  newNode->data = data;

  if (cdlist_empty(list)) {
    newNode->next = newNode;
    newNode->prev = newNode;
    list->first = newNode;
  } else {
    newNode->next = list->first;
    newNode->prev = list->first->prev;
    list->first->prev->next = newNode;
  }

  list->first->prev = newNode;
}

void cdlist_traverse(CDList * list, CDListTraverseOrder order,
                     VisitFunction visit) {
  if (cdlist_empty(list)) {
    return;
  }

  DNode *node;
  switch (order) {
  case CDLIST_TRAVERSE_FORWARD:
    node = list->first;
    do {
      visit(node->data);
      node = node->next;
    } while (node != list->first);
    break;
  case CDLIST_TRAVERSE_BACKWARD:
    node = list->first->prev;
    do {
      visit(node->data);
      node = node->prev;
    } while (node != list->first->prev);
    break;
  }
}
