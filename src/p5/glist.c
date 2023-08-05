#include "glist.h"

#include <assert.h>
#include <stdlib.h>

GList glist_create() { return NULL; }

void glist_destroy(GList list, DestroyFunction destroy) {
  GNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}

int glist_empty(GList list) { return (list == NULL); }

GList glist_add_first(GList list, void *data, CopyFunction copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}

void glist_traverse(GList list, VisitExtraFunction visit, void *extra) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(extra, node->data);
}

GList glist_filter(GList list, CopyFunction c, Predicate p) {
  GList newList = glist_create();
  for (GNode *node = list; node != NULL; node = node->next) {
    if (p(node->data)) {
      newList = glist_add_first(newList, node->data, c);
    }
  }
  return newList;
}

void *glist_search(GList list, void *data, CompareFunction comp) {
  for (; list != NULL; list = list->next) 
    if (comp(list->data, data) == 0)
      return list->data;
  return NULL;
}

GList glist_delete(GList list, void *data, CompareFunction comp, 
                  DestroyFunction destroy, int *found) {

  if (glist_empty(list))
    return list;

  if (comp(list->data, data) == 0) {
    GNode *nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
    *found = 1;
    return list;
  }

  GNode *prev = list;
  GNode *curr = list->next;

  while (curr != NULL && comp(curr->data, data) != 0) 
    prev = curr, curr = curr->next;

  if (curr != NULL) {
    *found = 1;
    prev->next = curr->next;
    destroy(curr->data);
    free(curr);
  }

  return list; 
}