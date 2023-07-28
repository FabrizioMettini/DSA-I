#include "bstree.h"

#include <assert.h>
#include <stdlib.h>

struct _BST_Node {
  void *data;
  struct _BST_Node *left;
  struct _BST_Node *right;
};

BSTree bstree_create() { return NULL; }

void bstree_destroy(BSTree root, DestroyFunction destroy) {
  if (!bstree_empty(root)) {
    bstree_destroy(root->left, destroy);
    bstree_destroy(root->right, destroy);
    destroy(root->data);
    free(root);
  }
};

int bstree_empty(BSTree root) { return root == NULL; }

int bstree_search(BSTree root, void *data, CompareFunction comp) {
  if (bstree_empty(root))
    return 0;
  
  int ans = comp(root->data, data);
  
  if (ans > 0)
    return bstree_search(root->left, data, comp);
  
  else if (ans < 0) 
    return bstree_search(root->right, data, comp);
  
  else
    return 1;
}

BSTree bstree_insert(BSTree root, void *data, CopyFunction copy,
                       CompareFunction comp) {
  if (bstree_empty(root)) { 
    BSTree newNode = malloc(sizeof(struct _BST_Node));
    assert(newNode != NULL);
    newNode->data = copy(data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  int ans = comp(root->data, data); 

  if (ans > 0)
    root->left = bstree_insert(root->left, data, copy, comp);
  
  else if (ans < 0)
    root->right = bstree_insert(root->right, data, copy, comp);
  
  return root;
}

void bstree_traverse_extra(BSTree root, BSTreeTraverseOrder order,
                     VisitExtraFunction visit, void *extra) {
  if (bstree_empty(root))
    return;
  
  switch (order) {
  case BSTREE_TRAVERSE_PRE:
    visit(root->data, extra);
    bstree_traverse_extra(root->left, order, visit, extra);
    bstree_traverse_extra(root->right, order, visit, extra);
    break;
  case BSTREE_TRAVERSE_IN:
    bstree_traverse_extra(root->left, order, visit, extra);
    visit(root->data, extra);
    bstree_traverse_extra(root->right, order, visit, extra);
    break;
  case BSTREE_TRAVERSE_POST:
    bstree_traverse_extra(root->left, order, visit, extra);
    bstree_traverse_extra(root->right, order, visit, extra);
    visit(root->data, extra);
    break;
  }
}

BSTree bstree_minimum(BSTree root) {
  while (root->left != NULL)
    root = root->left;
  return root;
}

BSTree bstree_maximum(BSTree root) {
  while (root->right != NULL)
    root = root->right;
  return root;
}

BSTree bstree_succesor_father(BSTree root) {
  while (root->left->left != NULL)
    root = root->left;

  return root;
}

BSTree bstree_delete(BSTree root, void *data, CompareFunction comp,
                     DestroyFunction destroy) {
  if (bstree_empty(root))
    return NULL;

  int res = comp(root->data, data);

  if (res > 0)
    root->left = bstree_delete(root->left, data, comp, destroy);

  else if (res < 0)
    root->right = bstree_delete(root->right, data, comp, destroy);

  else {
    if (root->left == NULL && root->right == NULL) {
      destroy(root->data);
      free(root);
      return NULL;
    }

    else if (root->left != NULL && root->right != NULL) {
      BSTree successorFather = bstree_succesor_father(root->right);
      BSTree successor = successorFather->left;

      successorFather->left = (successor->right == NULL) ? NULL : successor->right;
      successor->left = root->left;
      successor->right = root->right;

      destroy(root->data);
      free(root);
      return successor;
    }

    else {
      BSTree aux = root->left == NULL ? root->right : root->left;
      destroy(root->data);
      free(root);
      return aux;
    }
  }

  return root;
}

static void *bstree_kth_smallest_helper(BSTree root, int k, int *count) {
  if (bstree_empty(root))
    return NULL;  
  
  void *data = bstree_kth_smallest_helper(root->left, k, count);
  
  if (data != NULL)
    return data;

  if (*count == k)
    return root->data; 
  
  (*count)++;
    
  return bstree_kth_smallest_helper(root->right, k, count);
}

void *bstree_kth_smallest(BSTree root, int k) {
  int *count = malloc(sizeof(int));
  *count = 0;
  BSTree kth_element = bstree_kth_smallest_helper(root, k, count);
  free(count);
  return kth_element;
}

static int bstree_validate_helper(BSTree root, CompareFunction comp,
                                    void *min, void *max) {
  if (bstree_empty(root))
    return 1;

  if (min != NULL && comp(root->data, min) < 0)
    return 0;

  if (max != NULL && comp(root->data, max) > 0)
    return 0;

  return bstree_validate_helper(root->left, comp, min, root->data)
         && bstree_validate_helper(root->right, comp, root->data, max);
}

int bstree_validate(BSTree root, CompareFunction comp) {
  return bstree_validate_helper(root, comp, NULL, NULL);
}