#ifndef __BSTREE_H__
#define __BSTREE_H__

typedef void *(*CopyFunction)(void *data);
typedef int (*CompareFunction)(void *data1, void *data2);
typedef void (*DestroyFunction)(void *data);
typedef void (*VisitExtraFunction)(void *data, void *extra);

typedef enum {
  BSTREE_TRAVERSE_IN,
  BSTREE_TRAVERSE_PRE,
  BSTREE_TRAVERSE_POST
} BSTreeTraverseOrder;

typedef struct _BST_Node *BSTree;

BSTree bstree_create();

void bstree_destroy(BSTree, DestroyFunction);

int bstree_empty(BSTree);

int bstree_search(BSTree, void *, CompareFunction);

BSTree bstree_insert(BSTree, void *, CopyFunction, CompareFunction);

void bstree_traverse_extra(BSTree, BSTreeTraverseOrder, VisitExtraFunction,
                     void *extra);

BSTree bstree_minimum(BSTree);

BSTree bstree_maximum(BSTree);

BSTree bstree_delete(BSTree, void *,
                     CompareFunction, DestroyFunction);

void *bstree_kth_smallest(BSTree, int);

int bstree_validate(BSTree, CompareFunction);

#endif //__BSTREE_H__