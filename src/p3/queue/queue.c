#include "gdlist.h"
#include "queue.h"

Queue queue_create() {
  return gdlist_create();
}

void queue_destroy(Queue queue, DestroyFunction destroy) {
  gdlist_destroy(queue, destroy);
}

int queue_empty(Queue queue) {
  return gdlist_empty(queue);
}

void *queue_front(Queue queue) {
  return gdlist_first(queue);
}

Queue queue_push(Queue queue, void *data, CopyFunction copy) {
  return gdlist_add_last(queue, data, copy);
}

Queue queue_pop(Queue queue, DestroyFunction destroy) {
  return gdlist_remove_first(queue, destroy);
}

void queue_print(Queue queue, VisitFunction visit) {
  gdlist_traverse(queue, visit);
}
