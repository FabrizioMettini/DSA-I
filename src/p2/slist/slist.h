#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*VisitFunction) (int data);

typedef struct _SNode {
  int data;
  struct _SNode *next;
} SNode;

typedef SNode *SList;

SList slist_create();

void slist_destroy(SList list);

int slist_empty(SList list);

SList slist_add_last(SList list, int data);

SList slist_add_first(SList list, int data);

void slist_traverse(SList list, VisitFunction visit);

#endif /* __SLIST_H__ */
