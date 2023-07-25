#include "bheap.h"

#include <assert.h>
#include <stdlib.h>

BHeap bheap_create(int capacity, CompareFunction comp) {
  BHeap bheap = malloc(sizeof(struct _BHeap));
  assert(bheap != NULL);
  
  bheap->arr = malloc(sizeof(void *) * (capacity + 1));
  assert(bheap->arr != NULL);
  
  for (int i = 0; i <= capacity; i++) 
    bheap->arr[i] = NULL;
  
  bheap->capacity = capacity;
  bheap->last = 0;
  bheap->comp = comp;

  return bheap;
}

void bheap_destroy(BHeap bheap, DestroyFunction destroy) {
  for (int i = 0; i <= bheap->last; i++)
    destroy(bheap->arr[i]);
  free(bheap->arr);
  free(bheap);
}

int bheap_is_empty(BHeap bheap) { return bheap->last == 0; }

void bheap_traverse(BHeap bheap, VisitFunction visit) {
  for (int i = 1; i <= bheap->last; i++)
    visit(bheap->arr[i]);
}

BHeap bheap_insert(BHeap bheap, void *data, CopyFunction copy) {
  if (bheap->last == bheap->capacity) {
    bheap->arr = realloc(bheap->arr, sizeof(void *) * (bheap->capacity * 2 + 1));
    bheap->capacity *= 2;
  } 
  
  bheap->last += 1;
  bheap->arr[bheap->last] = copy(data); 

  int j = bheap->last; 
  while (j > 1 && bheap->comp(bheap->arr[j], bheap->arr[j/2])) {
    void *temp = bheap->arr[j];
    bheap->arr[j] = bheap->arr[j/2];
    bheap->arr[j/2] = temp;
    j /= 2;
  }

  return bheap;
}

BHeap bheap_delete(BHeap bheap, DestroyFunction destroy) {
  if (bheap_is_empty(bheap)) 
    return bheap;

  void *nodeToDelete = bheap->arr[1]; 
  bheap->arr[1] = bheap->arr[bheap->last];
  destroy(nodeToDelete); 
  bheap->last -= 1; 

  int isGreater = 1;
  int j = 1;

  while (2*j <= bheap->last && isGreater) {
    int k = 2 * j;

    if (k + 1 <= bheap->last && bheap->comp(bheap->arr[k+1], bheap->arr[k]))
      k += 1;

    if (bheap->comp(bheap->arr[j], bheap->arr[k]))
      isGreater = 0;
    else {
      void *temp = bheap->arr[j];
      bheap->arr[j] = bheap->arr[k];
      bheap->arr[k] = temp;
      j = k;
    }
  }

  return bheap;
}