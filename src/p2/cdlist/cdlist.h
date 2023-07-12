#ifndef __CDLIST_H__
#define __CDLIST_H__

typedef void (*VisitFunction)(int data);

typedef struct _DNode {
  int data;
  struct _DNode *next;
  struct _DNode *prev;
} DNode;

typedef struct {
  DNode *first;
} CDList;

typedef enum {
  CDLIST_TRAVERSE_FORWARD,
  CDLIST_TRAVERSE_BACKWARD
} CDListTraverseOrder;

CDList *cdlist_create();

void cdlist_destroy(CDList * list);

int cdlist_empty(CDList * list);

void cdlist_add_first(CDList * list, int data);

void cdlist_add_last(CDList * list, int data);

void cdlist_traverse(CDList * list, CDListTraverseOrder order,
                     VisitFunction visit);

#endif                          /* __CDLIST_H__ */
