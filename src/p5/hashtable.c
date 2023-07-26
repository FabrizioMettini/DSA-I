#include "hashtable.h"

#include <assert.h>
#include <stdlib.h>

typedef struct {
  void *data;
} HashtableCell;

struct _Hashtable {
  HashtableCell *elems;
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

  ht->elems = malloc(sizeof(HashtableCell) * capacity);
  assert(ht->elems != NULL);

  ht->nelems = 0;
  ht->capacity = capacity;
  ht->copy = copy;
  ht->comp = comp;
  ht->destr = destr;
  ht->hash = hash;

  for (unsigned idx = 0; idx < capacity; ++idx)
    ht->elems[idx].data = NULL;

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

  if (ht->elems[idx].data == NULL) {
    ht->nelems++;
    ht->elems[idx].data = ht->copy(data);
    return;
  }

  else if (ht->comp(ht->elems[idx].data, data) == 0) {
    ht->destr(ht->elems[idx].data);
    ht->elems[idx].data = ht->copy(data);
    return;
  }

  else {
    return;
  }
}

void *hashtable_search(Hashtable ht, void *data) {
  unsigned idx = ht->hash(data) % ht->capacity;

  if (ht->elems[idx].data == NULL)
    return NULL;

  else if (ht->comp(ht->elems[idx].data, data) == 0)
    return ht->elems[idx].data;

  else
    return NULL;
}

void hashtable_delete(Hashtable ht, void *data) {
  unsigned idx = ht->hash(data) % ht->capacity;

  if (ht->elems[idx].data == NULL)
    return;

  else if (ht->comp(ht->elems[idx].data, data) == 0) {
    ht->nelems--;
    ht->destr(ht->elems[idx].data);
    ht->elems[idx].data = NULL;
    return;
  }
}
