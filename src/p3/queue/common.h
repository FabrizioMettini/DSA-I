#ifndef __COMMON_H__
#define __COMMON_H__

typedef void (*DestroyFunction)(void *data);
typedef void *(*CopyFunction)(void *data);
typedef void (*VisitFunction)(void *data);

#endif /* __COMMON_H__ */