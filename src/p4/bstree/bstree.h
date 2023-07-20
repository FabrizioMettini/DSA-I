#ifndef __BSTREE_H__
#define __BSTREE_H__

typedef void *(*CopyFunction)(void *data);
typedef int (*CompareFunction)(void *, void *);
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

int bstree_search(BSTree, void *, CompareFunction);

BSTree bstree_insert(BSTree, void *, CopyFunction, CompareFunction);

void bstree_traverse(BSTree, BSTreeTraverseOrder, VisitExtraFunction,
                     void *extra);

#endif //__BSTREE_H__