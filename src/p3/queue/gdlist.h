#ifndef __GDLIST_H__
#define __GDLIST_H__

#include "common.h"

typedef struct _GDNode {
  void *data;
  struct _GDNode *next;
  struct _GDNode *prev;
} GDNode;

typedef struct _GDList {
  GDNode *first;
  GDNode *last;
} *GDList;

GDList gdlist_create();

void gdlist_destroy(GDList list, DestroyFunction destroy);

unsigned int gdlist_empty(GDList list);

void *gdlist_first(GDList list);

void *gdlist_last(GDList list);

GDList gdlist_add_first(GDList list, void *data, CopyFunction copy);

GDList gdlist_add_last(GDList list, void *data, CopyFunction copy);

GDList gdlist_remove_first(GDList list, DestroyFunction destroy);

GDList gdlist_remove_last(GDList list, DestroyFunction destroy);

void gdlist_traverse(GDList list, VisitFunction visit);

#endif /* __GDLIST_H__ */
