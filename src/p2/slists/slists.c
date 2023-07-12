#include "slists.h"

#include <stdlib.h>

SList slists_create() {
  SList list = malloc(sizeof(sizeof(struct _SList)));
  list->first = NULL;
  list->last = NULL;
  return list;
}

void slists_destroy(SList list) {
  SNode *temp = list->first;
  SNode *nodeToDelete;

  while (temp != NULL) {
    nodeToDelete = temp;
    temp = temp->next;
    free(nodeToDelete);
  }

  free(list);
}

void slists_add_last(SList list, int data) {
  SNode *newNode = malloc(sizeof(SNode));
  newNode->data = data;
  newNode->next = NULL;

  if (list->last != NULL) {
    list->last->next = newNode;
  }

  list->last = newNode;

  if (list->first == NULL) {
    list->first = newNode;
  }
}

void slists_add_first(SList list, int data) {
  SNode *newNode = malloc(sizeof(SNode));
  newNode->data = data;
  newNode->next = list->first;
  list->first = newNode;

  if (list->last == NULL) {
    list->last = newNode;
  }
}

void slists_traverse(SList list, VisitFunction visit) {
  for (SNode * node = list->first; node != NULL; node = node->next) {
    visit(node->data);
  }
}
