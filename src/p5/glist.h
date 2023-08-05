#ifndef __GLIST_H__
#define __GLIST_H__

#include "common.h"

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;

GList glist_create();

void glist_destroy(GList list, DestroyFunction destroy);

int glist_empty(GList list);

GList glist_add_first(GList list, void *data, CopyFunction copy);

void glist_traverse(GList list, VisitExtraFunction visit, void *extra);

GList glist_filter(GList list, CopyFunction c, Predicate p);

void *glist_search(GList list, void *data, CompareFunction comp);

GList glist_delete(GList list, void *data, CompareFunction comp, DestroyFunction destroy, int *found);

#endif /* __GLIST_H__ */
