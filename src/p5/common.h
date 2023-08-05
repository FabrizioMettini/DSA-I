#ifndef __COMMON_H__
#define __COMMON_H__

typedef void *(*CopyFunction)(void *data);
typedef int (*CompareFunction)(void *data1, void *data2);
typedef void (*DestroyFunction)(void *data);
typedef unsigned (*HashFunction)(void *data);
typedef int (*Predicate)(void *data);
typedef void (*VisitExtraFunction)(void *data, void *extra);

#endif /* __COMMON_H__ */