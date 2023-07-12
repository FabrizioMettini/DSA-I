#ifndef __DLIST_H__
#define __DLIST_H__

typedef void (*VisitFunction)(int data);

typedef struct _DNode {
  int data;
  struct _DNode *next;
  struct _DNode *prev;
} DNode;

typedef struct {
  DNode *first;
  DNode *last;
} DList;

typedef enum {
  DLIST_TRAVERSE_FORWARD,
  DLIST_TRAVERSE_BACKWARD
} DListTraverseOrder;

DList *dlist_create();

void dlist_destroy(DList * list);

int dlist_empty(DList * list);

void dlist_add_first(DList * list, int data);

void dlist_add_last(DList * list, int data);

void dlist_traverse(DList * list, DListTraverseOrder order,
                    VisitFunction visit);

#endif                          /* __DLIST_H__ */
