#include "gdlist.h"

#include <assert.h>
#include <stdlib.h>

GDList gdlist_create() {
  GDList list = malloc(sizeof(struct _GDList));
  assert(list != NULL);
  list->first = NULL;
  list->last = NULL;
  return list;
}

void gdlist_destroy(GDList list, DestroyFunction destroy) {
  GDNode *temp = list->first;
  GDNode *nodeToDelete;

  while (temp != NULL) {
    nodeToDelete = temp;
    temp = temp->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }

  free(list);
}

unsigned int gdlist_empty(GDList list) { return list->first == NULL; }

void *gdlist_first(GDList list) {
  if (gdlist_empty(list))
    return NULL;

  return list->first->data;
}

void *gdlist_last(GDList list) {
  if (gdlist_empty(list))
    return NULL;

  return list->last->data;
}

GDList gdlist_add_first(GDList list, void *data, CopyFunction copy) {
  GDNode *newNode = malloc(sizeof(struct _GDNode));
  assert(newNode != NULL);
  newNode->data = copy(data);
  newNode->prev = NULL;
  newNode->next = list->first;
  
  if (gdlist_empty(list))
    list->last = newNode;
  else 
    list->first->prev = newNode;

  list->first = newNode;
  return list;
}

GDList gdlist_add_last(GDList list, void *data, CopyFunction copy) {
  GDNode *newNode = malloc(sizeof(struct _GDNode));
  assert(newNode != NULL);
  newNode->data = copy(data);
  newNode->next = NULL;
  newNode->prev = list->last;
  
  if (gdlist_empty(list))
    list->first = newNode;
  else 
    list->last->next = newNode;

  list->last = newNode;
  return list;
}

GDList gdlist_remove_first(GDList list, DestroyFunction destroy) {
  if (gdlist_empty(list))
    return list;

  GDNode *nodeToDelete = list->first;
  list->first = nodeToDelete->next;

  if (nodeToDelete->next == NULL)
    list->last = NULL;
  else
    nodeToDelete->next->prev = NULL;

  destroy(nodeToDelete->data);
  free(nodeToDelete);

  return list;
}

GDList gdlist_remove_last(GDList list, DestroyFunction destroy) {
  if (gdlist_empty(list))
    return list;

  GDNode *nodeToDelete = list->last;
  list->last = nodeToDelete->prev;

  if (nodeToDelete->prev == NULL)
    list->first = NULL;
  else
    nodeToDelete->prev->next = NULL;
  
  destroy(nodeToDelete->data);
  free(nodeToDelete);

  return list;
}

void gdlist_traverse(GDList list, VisitFunction visit) {
  for (GDNode *node = list->first; node != NULL; node = node->next)
    visit(node->data);
}