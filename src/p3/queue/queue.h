#ifndef __Queue_H__
#define __Queue_H__

#include "common.h"
#include "gdlist.h"

typedef GDList Queue;

Queue queue_create();

void queue_destroy(Queue queue, DestroyFunction destroy);

int queue_empty(Queue queue);

void *queue_front(Queue queue);

Queue queue_push(Queue queue, void *data, CopyFunction copy);

Queue queue_pop(Queue queue, DestroyFunction destroy);

void queue_print(Queue queue, VisitFunction visit);

#endif /* __QUEUE_H__*/