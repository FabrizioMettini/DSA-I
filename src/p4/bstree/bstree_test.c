#include "bstree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_WORDS 16

static void *copy_string(void *data) {
  char *str = malloc(sizeof(char) * (strlen(data) + 1));
  assert(str != NULL);
  strcpy(str, data);
  return str;
}
static int compare_string(void *data1, void *data2) {
  return strcmp(data1, data2);
}
static void destroy_string(void *data) { free(data); }
static void print_string(void *data, __attribute__((unused)) void *extra) {
  printf("\"%s\" ", (char *)data);
}

int main() {
  char *words[N_WORDS] = {"cat",      "dog",    "house",     "person",
                          "park",    "tree",    "building", "street",
                          "argentina", "santa fe", "rosario",  "unr",
                          "edya",      "farmacy", "time",   "phone"};

  BSTree tree = bstree_create();
  for (int i = 0; i < N_WORDS; i++)
    tree = bstree_insert(tree, words[i], copy_string, compare_string);

  printf("INORDER: ");
  bstree_traverse(tree, BSTREE_TRAVERSE_IN, print_string, NULL);
  puts("");

  assert(bstree_search(tree, "farmacy", compare_string) == 1);
  assert(bstree_search(tree, "santa fe", compare_string) == 1);
  assert(bstree_search(tree, "person", compare_string) == 1);
  assert(bstree_search(tree, "unr", compare_string) == 1);
  assert(bstree_search(tree, "argentina", compare_string) == 1);
  assert(bstree_search(tree, "telephone", compare_string) == 0);
  assert(bstree_search(tree, "mail", compare_string) == 0);
  assert(bstree_search(tree, "EDyA1", compare_string) == 0);

  bstree_destroy(tree, destroy_string);

  return 0;
}
