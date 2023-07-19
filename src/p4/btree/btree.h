#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*VisitFunction)(int data);
typedef void (*VisitExtraFunction)(int data, void *extra);

typedef enum {
  BTREE_TRAVERSE_IN,
  BTREE_TRAVERSE_PRE,
  BTREE_TRAVERSE_POST
} BTreeTraverseOrder;

typedef struct _BTNode *BTree;

BTree btree_create();

void btree_destroy(BTree node);

int btree_empty(BTree node);

BTree btree_join(int data, BTree left, BTree right);

void btree_traverse(BTree tree, BTreeTraverseOrder order,
                    VisitFunction visit);

int btree_nnodes(BTree tree);

int btree_find(BTree tree, int x);

BTree btree_copy(BTree tree);

int btree_height(BTree tree);

int btree_nnodes_depth(BTree tree, int depth);

int btree_depth(BTree tree, int x);

int btree_sum(BTree tree);

void btree_traverse_extra(BTree tree, BTreeTraverseOrder order,
  VisitExtraFunction visit, void *extra);

#endif /* __BTREE_H__ */
