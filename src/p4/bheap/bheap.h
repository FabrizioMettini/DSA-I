#ifndef __BHEAP_H__
#define __BHEAP_H__

typedef int (*CompareFunction)(void *, void*);
typedef void *(*CopyFunction)(void *);
typedef void (*DestroyFunction)(void *);
typedef void (*VisitFunction)(void *);

typedef struct _BHeap {
    void **arr;
    int capacity;
    int last;
    CompareFunction comp;
} *BHeap;

BHeap bheap_create(int capacity, CompareFunction comp);

void bheap_destroy(BHeap bheap, DestroyFunction destroy);

int bheap_is_empty(BHeap bheap);

void bheap_traverse(BHeap bheap, VisitFunction visit);

BHeap bheap_insert(BHeap bheap, void *data, CopyFunction copy);

BHeap bheap_delete(BHeap bheap, DestroyFunction destroy);

#endif