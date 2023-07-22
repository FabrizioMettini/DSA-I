#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// ==============================================
// SOLUTION 1
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int find_repeated(int arr[], int len) {
  int i, j;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (arr[i] == arr[j] && i != j)
        return i;
    }
  }
  return -1;
}

// ==============================================
// SOLUTION 2
// Time Complexity: O(nlog(n))
// Space Complexity: O(n)

typedef struct _Pair {
  int elem;
  int index;
} Pair;

int compare_pairs(const void *a, const void *b) {
  Pair *pair_a = (Pair *) a;
  Pair *pair_b = (Pair *) b;
  if (pair_a->elem > pair_b->elem) return 1;
  if (pair_a->elem < pair_b->elem) return -1;
  return 0;
}

int find_repeated_2(int arr[], int len) {
  Pair p[len];
  for (int i = 0; i < len; i++) {
    p[i].elem = arr[i];
    p[i].index = i;
  }
  qsort(p, len, sizeof(Pair), compare_pairs);
  for (int i = 0; i < len-1; i++) {
    if (p[i].elem == p[i+1].elem) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr1[] = {1, 2, 5, 3, 2, 4};
  int arr2[] = {1, 2, 5, 3, 6, 4};
  assert(find_repeated(arr1, 6) == find_repeated_2(arr1, 6));
  assert(find_repeated(arr2, 6) == find_repeated_2(arr2, 6));
  return 0;
}