#ifndef __GLIST_H__
#define __GLIST_H__

typedef void (*DestroyFunction)(void *data);
typedef int (*Predicate)(void *data);
typedef void *(*CopyFunction)(void *data);
typedef void (*VisitFunction)(void *data);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;

GList glist_create();

void glist_destroy(GList list, DestroyFunction destroy);

int glist_empty(GList list);

GList glist_add_first(GList list, void *data, CopyFunction copy);

void glist_traverse(GList list, VisitFunction visitar);

GList glist_filter(GList list, CopyFunction c, Predicate p);

#endif /* __GLIST_H__ */
