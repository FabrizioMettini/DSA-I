#ifndef __INTARRAY__
#define __INTARRAY__

typedef struct {
  int *address;
  int capacity;
} IntArray;

IntArray *int_array_create(int capacity);

void int_array_destroy(IntArray * intArray);

int int_array_read(IntArray * intArray, int pos);

void int_array_write(IntArray * intArray, int pos, int data);

int int_array_capacity(IntArray * intArray);

void int_array_print(IntArray * intArray);

void int_array_resize(IntArray * intArray, int capacity);

void int_array_insert(IntArray * intArray, int pos, int data);

void int_array_delete(IntArray * intArray, int pos);

#endif
