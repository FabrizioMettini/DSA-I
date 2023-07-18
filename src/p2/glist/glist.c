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


void glist_traverse(GList list, VisitFunction visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
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