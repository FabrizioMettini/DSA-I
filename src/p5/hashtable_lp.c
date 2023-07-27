#include "glist.h"
#include "hashtable.h"

#include <assert.h>
#include <stdlib.h>

typedef struct _Bucket {
  void *data;
  unsigned deleted;
} Bucket;

struct _Hashtable {
  Bucket *elems;
  unsigned nelems;
  unsigned capacity;
  CopyFunction copy;
  CompareFunction comp;
  DestroyFunction destr;
  HashFunction hash;
};

int bucket_empty(Bucket bucket) {
  return bucket.data == NULL && bucket.deleted == 0;
}

Hashtable hashtable_create(unsigned capacity, CopyFunction copy,
                          CompareFunction comp, DestroyFunction destr,
                          HashFunction hash) {

  Hashtable ht = malloc(sizeof(struct _Hashtable));
  assert(ht != NULL);

  ht->elems = malloc(sizeof(Bucket) * capacity);
  assert(ht->elems != NULL);

  ht->nelems = 0;
  ht->capacity = capacity;
  ht->copy = copy;
  ht->comp = comp;
  ht->destr = destr;
  ht->hash = hash;

  for (unsigned idx = 0; idx < capacity; ++idx) {
    ht->elems[idx].data = NULL;
    ht->elems[idx].deleted = 0;
  }

  return ht;
}

int hashtable_nelems(Hashtable ht) { return ht->nelems; }

int hashtable_capacity(Hashtable ht) { return ht->capacity; }

void hashtable_destroy(Hashtable ht) {
  for (unsigned idx = 0; idx < ht->capacity; ++idx)
    if (ht->elems[idx].data != NULL)
      ht->destr(ht->elems[idx].data);
  free(ht->elems);
  free(ht);
}

void hashtable_insert(Hashtable ht, void *data) {
  unsigned idx = ht->hash(data) % ht->capacity;

  while (!bucket_empty(ht->elems[idx])) {
    if (ht->elems[idx].data != NULL && ht->comp(ht->elems[idx].data, data) == 0) {
      ht->destr(ht->elems[idx].data);
      ht->nelems--;
      break;
    } 
    
    idx = (idx + 1) % ht->capacity;
  }
  
  ht->elems[idx].data = ht->copy(data);
  ht->nelems++;
}

static int hashtable_find(Hashtable ht, void *data) {
  int idx = ht->hash(data) % ht->capacity;

  while (!bucket_empty(ht->elems[idx])) {
    if (ht->elems[idx].data != NULL && ht->comp(ht->elems[idx].data, data) == 0)
      return idx;

    idx = (idx + 1) % ht->capacity;
  }

  return -1;    
}

void *hashtable_search(Hashtable ht, void *data) {
  int idx = hashtable_find(ht, data);
  if (idx != -1)
    return ht->elems[idx].data;
  return NULL;
}

void hashtable_delete(Hashtable ht, void *data) {
  int idx = hashtable_find(ht, data);
  if (idx != -1) {
    ht->destr(ht->elems[idx].data);
    ht->elems[idx].data = NULL;
    ht->elems[idx].deleted = 1;
  }
}