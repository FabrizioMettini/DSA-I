#include "avl.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _AVL_Node {
  void *data;
  struct _AVL_Node *left;
  struct _AVL_Node *right;
  int height;
} AVL_Node;

struct _AVL {
  AVL_Node *root;
  CopyFunction copy;
  CompareFunction comp;
  DestroyFunction destr;
};

AVL avl_create(CopyFunction copy, CompareFunction comp,
               DestroyFunction destr) {

  AVL avl = malloc(sizeof(struct _AVL));
  assert(avl != NULL);
  avl->root = NULL;
  avl->copy = copy;
  avl->comp = comp;
  avl->destr = destr;
  return avl;
}

static void avl_node_destroy(AVL_Node *root, DestroyFunction destr) {
  if (root != NULL) {
    avl_node_destroy(root->left, destr);
    avl_node_destroy(root->right, destr);
    destr(root->data);
    free(root);
  }
}

void avl_destroy(AVL avl) {
  avl_node_destroy(avl->root, avl->destr);
  free(avl);
}

static int avl_node_search(AVL_Node *root, CompareFunction comp,
                           void *data) {
  if (root == NULL)
    return 0;
  
  else if (comp(data, root->data) == 0)
    return 1;

  else if (comp(data, root->data) < 0)
    return avl_node_search(root->left, comp, data);
  
  else
    return avl_node_search(root->right, comp, data);
}

int avl_search(AVL avl, void *data) {
  return avl_node_search(avl->root, avl->comp, data);
}

static int avl_node_height(AVL_Node *root) {
  return (root == NULL ? -1 : root->height);
}

static unsigned int avl_node_max_height_children(AVL_Node *root) {
  assert(root != NULL);
  int heightLeft = avl_node_height(root->left);
  int heightRight = avl_node_height(root->right);
  return (heightLeft < heightRight ? heightRight : heightLeft);
}

static int avl_node_balance_factor(AVL_Node *root) {
  assert(root != NULL);
  int factor = avl_node_height(root->right) - avl_node_height(root->left);
  assert(-2 <= factor || factor <= 2);
  return factor;
}

static AVL_Node *avl_node_simple_left_rotation(AVL_Node *root) {
  AVL_Node *rightChild = root->right;
  assert(rightChild != NULL);
  root->right = rightChild->left;
  rightChild->left = root;
  root->height = 1 + avl_node_max_height_children(root);
  rightChild->height = 1 + avl_node_max_height_children(rightChild);
  return rightChild;
}

static AVL_Node *avl_node_simple_right_rotation(AVL_Node *root) {
  AVL_Node *leftChild = root->left;
  assert(leftChild != NULL);
  root->left = leftChild->right;
  leftChild->right = root;
  root->height = 1 + avl_node_max_height_children(root);
  leftChild->height = 1 + avl_node_max_height_children(leftChild);
  return leftChild;
}

static AVL_Node *avl_node_create(void *data, CopyFunction copy) {
  AVL_Node *newNode = malloc(sizeof(AVL_Node));
  assert(newNode != NULL);
  newNode->data = copy(data);
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 0;
  return newNode;
}

static AVL_Node *avl_node_insert(AVL_Node *root, void *data,
                                 CopyFunction copy, 
                                 CompareFunction comp) {

  if (root == NULL)
    return avl_node_create(data, copy);

  else if (comp(data, root->data) < 0) {
    root->left = avl_node_insert(root->left, data, copy, comp);
    if (avl_node_balance_factor(root) == -2) {
      if (avl_node_balance_factor(root->left) == 1)
        root->left = avl_node_simple_left_rotation(root->left);
      root = avl_node_simple_right_rotation(root);
    }
    root->height = 1 + avl_node_max_height_children(root);
    return root;
  }

  else if (comp(root->data, data) < 0) {
    root->right = avl_node_insert(root->right, data, copy, comp);
    if (avl_node_balance_factor(root) == 2) {
      if (avl_node_balance_factor(root->right) == -1)
        root->right = avl_node_simple_right_rotation(root->right);
      root = avl_node_simple_left_rotation(root);
    }
    root->height = 1 + avl_node_max_height_children(root);
    return root;
  }

  else
    return root;
}

void avl_insert(AVL avl, void *data) {
  avl->root = avl_node_insert(avl->root, data, avl->copy, avl->comp);
}

static AVL_Node *avl_node_successor_father(AVL_Node *root) {
  while (root->left->left != NULL) 
    root = root->left;
  return root;
}

static AVL_Node *avl_node_delete(AVL_Node *root, void *data,
                                 DestroyFunction destr, 
                                 CompareFunction comp) {

  if (root == NULL)
    return NULL;

  int ans = comp(root->data, data);

  if (ans > 0)
    root->left = avl_node_delete(root->left, data, destr, comp);

  else if (ans < 0)
    root->right = avl_node_delete(root->right, data, destr, comp);

  else {
    if (root->left == NULL && root->right == NULL) {
      destr(root->data);
      free(root);
      return NULL;
    }

    else if (root->left != NULL && root->right != NULL) {
      AVL_Node *successorFather = avl_node_successor_father(root->right);
      AVL_Node *successor = successorFather->left;
  
      successorFather->left = successor->right;
      successor->left = root->left;
      successor->right = root->right;

      destr(root->data);
      free(root);

      successorFather->height = 1 + avl_node_max_height_children(successorFather);
      successor->height = 1 + avl_node_max_height_children(successor);
      return successor;
    }

    else {
      AVL_Node *aux = root->left == NULL ? root->right : root->left;
      destr(root->data);
      free(root);
      return aux;
    }
  }

  root->height = 1 + avl_node_max_height_children(root);
  
  if (avl_node_balance_factor(root) == -2) {
    if (avl_node_balance_factor(root->left) == 1)
      root->left = avl_node_simple_left_rotation(root->left);
    root = avl_node_simple_right_rotation(root);
    root->height = 1 + avl_node_max_height_children(root);
  }

  if (avl_node_balance_factor(root) == 2) {
    if (avl_node_balance_factor(root->right) == -1)
      root->right = avl_node_simple_right_rotation(root->right);
    root = avl_node_simple_left_rotation(root);
    root->height = 1 + avl_node_max_height_children(root);
  }

  return root;
}  

void avl_delete(AVL avl, void *data) {
  avl->root = avl_node_delete(avl->root, data, avl->destr, avl->comp);
}

static int avl_node_validate_bst(AVL_Node *root, void *min, void *max,
                                 CompareFunction comp) {
  if (root == NULL)
    return 1;

  else {
    if (min != NULL && comp(root->data, min) <= 0)
      return 0;

    if (max != NULL && comp(max, root->data) <= 0)
      return 0;

    return (avl_node_validate_bst(root->left, min, root->data, comp) 
            && avl_node_validate_bst(root->right, root->data, max, comp));
  }
}

static int avl_node_validate_height_and_balance(AVL_Node *root) {
  if (root == NULL)
    return 1;

  int ret1 = avl_node_validate_height_and_balance(root->left);
  int ret2 = avl_node_validate_height_and_balance(root->right);

  if (ret1 && ret2) {
    int height = 1 + avl_node_max_height_children(root);
    int factor = avl_node_balance_factor(root);
    if ((root->height == height) && (factor >= -1) && (factor <= 1))
      return 1;
  }

  return 0;
}

int avl_validate(AVL avl) {
  return (avl_node_validate_height_and_balance(avl->root) 
          && avl_node_validate_bst(avl->root, NULL, NULL, avl->comp));
}

static void avl_node_traverse(AVL_Node *root, AVLTraverseOrder order,
                            VisitExtraFunction visit, void *extra) {

  if (root != NULL) {
    if (order == AVL_TRAVERSE_ORDER_PRE)
      visit(root->data, extra);
    avl_node_traverse(root->left, order, visit, extra);
    if (order == AVL_TRAVERSE_ORDER_IN)
      visit(root->data, extra);
    avl_node_traverse(root->right, order, visit, extra);
    if (order == AVL_TRAVERSE_ORDER_POST)
      visit(root->data, extra);
  }
}
void avl_traverse(AVL avl, AVLTraverseOrder order, VisitExtraFunction visit,
                  void *extra) {
  avl_node_traverse(avl->root, order, visit, extra);
}
