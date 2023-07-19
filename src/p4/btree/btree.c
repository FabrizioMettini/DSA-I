#include "btree.h"

#include <assert.h>
#include <stdlib.h>

struct _BTNode {
  int data;
  struct _BTNode *left;
  struct _BTNode *right;
};

BTree btree_create() { return NULL; }

void btree_destroy(BTree node) {
  if (node != NULL) {
    btree_destroy(node->left);
    btree_destroy(node->right);
    free(node);
  }
}

int btree_empty(BTree node) { return node == NULL; }

BTree btree_join(int data, BTree left, BTree right) {
  BTree newNode = malloc(sizeof(struct _BTNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->left = left;
  newNode->right = right;
  return newNode;
}

void btree_traverse(BTree tree, BTreeTraverseOrder order,
                    VisitFunction visit) {
  
  if (btree_empty(tree)) {
    return;
  }

  switch (order) {
  case BTREE_TRAVERSE_PRE:
    visit(tree->data);
    btree_traverse(tree->left, order, visit);
    btree_traverse(tree->right, order, visit);
    break;
  case BTREE_TRAVERSE_IN:
    btree_traverse(tree->left, order, visit);
    visit(tree->data);
    btree_traverse(tree->right, order, visit);
    break;
  case BTREE_TRAVERSE_POST:
    btree_traverse(tree->left, order, visit);
    btree_traverse(tree->right, order, visit);
    visit(tree->data);
    break;
  }
}

int btree_nnodes(BTree tree) {
  if (btree_empty(tree)) {
    return 0;
  }

  return 1 + btree_nnodes(tree->left) + btree_nnodes(tree->right);
}

int btree_find(BTree tree, int x) {
  if (btree_empty(tree)) {
    return 0;
  }

  return tree->data == x || btree_find(tree->left, x) || btree_find(tree->right, x);
}

BTree btree_copy(BTree tree) {
  BTree tree_copy = btree_create();

  if (!btree_empty(tree)) {
    tree_copy->data = tree->data;
    tree_copy->left = btree_copy(tree->left);
    tree_copy->right = btree_copy(tree->right);
  }

  return tree_copy;
}

int btree_nnodes_depth(BTree tree, int depth) {
  if (btree_empty(tree)) {
    return 0;
  }

  if (depth == 0) {
    return 1;
  }

  return btree_nnodes_depth(tree->left, depth - 1) + btree_nnodes_depth(tree->right, depth - 1);
}

int btree_depth_util(BTree tree, int x, int curr_depth) {
  if (btree_empty(tree)) {
    return -1;
  }

  if (tree->data == x) {
    return curr_depth;
  }

  int l_depth = btree_depth_util(tree->left, x, curr_depth + 1);
  int r_depth = btree_depth_util(tree->right, x, curr_depth + 1);
  
  return l_depth > r_depth ? l_depth : r_depth;             
}

int btree_depth(BTree tree, int x) {
  return btree_depth_util(tree, x, 0);
}

int btree_height_util(BTree tree) {
  if (btree_empty(tree)) {
    return 0;
  }
  int l_height = btree_height_util(tree->left);
  int r_height = btree_height_util(tree->right);
  return 1 + (l_height > r_height ? l_height : r_height);
}

int btree_height(BTree tree) {
  if (btree_empty(tree)) {
    return -1;
  }

  return btree_height_util(tree) - 1;
}

int btree_sum(BTree tree) {
  if (btree_empty(tree)) {
    return 0;
  }

  return tree->data + btree_sum(tree->left) + btree_sum(tree->right);
}

void btree_traverse_extra(BTree tree, BTreeTraverseOrder order,
  VisitExtraFunction visit, void *extra) {

  if (btree_empty(tree)) {
    return;
  }

  switch (order) {
  case BTREE_TRAVERSE_PRE:
    visit(tree->data, extra);
    btree_traverse_extra(tree->left, order, visit, extra);
    btree_traverse_extra(tree->right, order, visit, extra);
    break;
  case BTREE_TRAVERSE_IN:
    btree_traverse_extra(tree->left, order, visit, extra);
    visit(tree->data, extra);
    btree_traverse_extra(tree->right, order, visit, extra);
    break;
  case BTREE_TRAVERSE_POST:
    btree_traverse_extra(tree->left, order, visit, extra);
    btree_traverse_extra(tree->right, order, visit, extra);
    visit(tree->data, extra);
    break;
  }
}