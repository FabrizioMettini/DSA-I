#ifndef __AVL_H__
#define __AVL_H__

typedef void *(*CopyFunction)(void *data);
typedef int (*CompareFunction)(void *, void *);
typedef void (*DestroyFunction)(void *data);
typedef void (*VisitExtraFunction)(void *data, void *extra);

typedef enum {
  AVL_TRAVERSE_ORDER_IN, 
  AVL_TRAVERSE_ORDER_PRE,
  AVL_TRAVERSE_ORDER_POST
} AVLTraverseOrder;

typedef struct _AVL *AVL;

AVL avl_create(CopyFunction, CompareFunction, DestroyFunction);

void avl_destroy(AVL);

int avl_search(AVL, void *);

void avl_insert(AVL, void *);

void avl_delete(AVL, void *);

int avl_validate(AVL);

void avl_traverse(AVL, AVLTraverseOrder, VisitExtraFunction, void *);

#endif /* __AVL_H__*/