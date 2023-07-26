#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

typedef void *(*CopyFunction)(void *data);
typedef int (*CompareFunction)(void *data1, void *data2);
typedef void (*DestroyFunction)(void *data);
typedef unsigned (*HashFunction)(void *data);

typedef struct _Hashtable *Hashtable;

Hashtable hashtable_create(unsigned capacity, CopyFunction copy,
                          CompareFunction comp, DestroyFunction destr,
                          HashFunction hash);

int hashtable_nelems(Hashtable ht);

int hashtable_capacity(Hashtable ht);

void hashtable_destroy(Hashtable ht);

void hashtable_insert(Hashtable ht, void *data);

void *hashtable_search(Hashtable ht, void *data);

void hashtable_delete(Hashtable ht, void *data);

#endif /* __HASHTABLE_H__ */