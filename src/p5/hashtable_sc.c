#include "glist.h"
#include "hashtable.h"

#include <assert.h>
#include <stdlib.h>

typedef GList Bucket;

struct _Hashtable {
  Bucket *elems;
  unsigned nelems;
  unsigned capacity;
  CopyFunction copy;
  CompareFunction comp;
  DestroyFunction destr;
  HashFunction hash;
};

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

  for (unsigned idx = 0; idx < capacity; ++idx)
    ht->elems[idx] = glist_create();

  return ht;
}

int hashtable_nelems(Hashtable ht) { return ht->nelems; }

int hashtable_capacity(Hashtable ht) { return ht->capacity; }

void hashtable_destroy(Hashtable ht) {
  for (unsigned idx = 0; idx < ht->capacity; ++idx)
    glist_destroy(ht->elems[idx], ht->destr);
  free(ht->elems);
  free(ht);
}

void hashtable_insert(Hashtable ht, void *data) {
  unsigned idx = ht->hash(data) % ht->capacity;
  
  int deleted = 0;
  ht->elems[idx] = glist_delete(ht->elems[idx], data, ht->comp, ht->destr, &deleted);
  
  if (!deleted)
    ht->nelems++;
  
  ht->elems[idx] = glist_add_first(ht->elems[idx], data, ht->copy);
}

void *hashtable_search(Hashtable ht, void *data) {
  unsigned idx = ht->hash(data) % ht->capacity;
  return glist_search(ht->elems[idx], data, ht->comp);
}

void hashtable_delete(Hashtable ht, void *data) {
  unsigned idx = ht->hash(data) % ht->capacity;

  int deleted = 0;
  ht->elems[idx] = glist_delete(ht->elems[idx], data, ht->comp, ht->destr, &deleted);

  if (deleted)
    ht->nelems--;
}