#include "slist.h"

#include <stdlib.h>

SList slist_create() {
  return NULL;
}

void slist_destroy(SList list) {
  SNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    free(nodeToDelete);
  }
}

int slist_empty(SList list) {
  return list == NULL;
}

SList slist_add_last(SList list, int data) {
  SNode *newNode = malloc(sizeof(SNode));
  newNode->data = data;
  newNode->next = NULL;

  if (list == NULL) {
    return newNode;
  }

  SList node = list;
  for (; node->next != NULL; node = node->next);

  node->next = newNode;
  return list;
}

SList slist_add_first(SList list, int data) {
  SNode *newNode = malloc(sizeof(SNode));
  newNode->data = data;
  newNode->next = list;
  return newNode;
}

void slist_traverse(SList list, VisitFunction visit) {
  for (SNode *node = list; node != NULL; node = node->next) {
    visit(node->data);
  }
}
