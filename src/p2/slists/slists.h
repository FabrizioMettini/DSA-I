#ifndef __SLISTS_H__
#define __SLISTS_H__

#include <stddef.h>

typedef void (*VisitFunction)(int data);

typedef struct _SNode {
  int data;
  struct _SNode *next;
} SNode;

typedef struct _SList {
  SNode *first;
  SNode *last;
} *SList;

SList slists_create();

void slists_destroy(SList list);

void slists_add_last(SList list, int data);

void slists_add_first(SList list, int data);

void slists_traverse(SList list, VisitFunction visit);

#endif                          /* __SLISTS_H__ */
