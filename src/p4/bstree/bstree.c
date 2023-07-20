#include "bstree.h"

#include <assert.h>
#include <stdlib.h>

struct _BST_Node {
  void *data;
  struct _BST_Node *left, *right;
};

BSTree bstree_create() { return NULL; }

void bstree_destroy(BSTree root, DestroyFunction destroy) {
  if (root != NULL) {
    bstree_destroy(root->left, destroy);
    bstree_destroy(root->right, destroy);
    destroy(root->data);
    free(root);
  }
};

int bstree_search(BSTree root, void *data, CompareFunction comp) {
  if (root == NULL) {
    return 0;
  } else if (comp(data, root->data) == 0) { 
    return 1;
  } else if (comp(data, root->data) < 0) {
    return bstree_search(root->left, data, comp);
  } else {
    return bstree_search(root->right, data, comp);
  }
}

BSTree bstree_insert(BSTree root, void *data, CopyFunction copy,
                       CompareFunction comp) {
  if (root == NULL) { 
    BSTree newNode = malloc(sizeof(struct _BST_Node));
    assert(newNode != NULL);
    newNode->data = copy(data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  } else if (comp(data, root->data) < 0) {
    root->left = bstree_insert(root->left, data, copy, comp);
  } else if (comp(data, root->data) > 0) {
    root->right = bstree_insert(root->right, data, copy, comp);
  }
  return root;
}

void bstree_traverse(BSTree root, BSTreeTraverseOrder orden,
                     VisitExtraFunction visita, void *extra) {
  if (root != NULL) {
    if (orden == BSTREE_TRAVERSE_PRE)
      visita(root->data, extra);
    bstree_traverse(root->left, orden, visita, extra);
    if (orden == BSTREE_TRAVERSE_IN)
      visita(root->data, extra);
    bstree_traverse(root->right, orden, visita, extra);
    if (orden == BSTREE_TRAVERSE_POST)
      visita(root->data, extra);
  }
}
