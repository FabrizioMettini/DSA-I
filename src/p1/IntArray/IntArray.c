#include <stdio.h>
#include <stdlib.h>
#include "IntArray.h"

IntArray *int_array_create(int capacity) {
  int *address = malloc(capacity * sizeof(int));
  IntArray *intArray = malloc(sizeof(IntArray));
  intArray->address = address;
  intArray->capacity = capacity;
  return intArray;
}

void int_array_destroy(IntArray * intArray) {
  free(intArray->address);
  free(intArray);
}

int int_array_read(IntArray * intArray, int pos) {
  return intArray->address[pos];
}

void int_array_write(IntArray * intArray, int pos, int data) {
  intArray->address[pos] = data;
}

int int_array_capacity(IntArray * intArray) {
  return intArray->capacity;
}

void int_array_print(IntArray * intArray) {
  for (int i = 0; i < intArray->capacity; i++) {
    printf("%d ", intArray->address[i]);
  }
  printf("\n");
}

void int_array_resize(IntArray * intArray, int capacity) {
  intArray->address = realloc(intArray->address, capacity * sizeof(int));
  intArray->capacity = capacity;
}

void int_array_insert(IntArray * intArray, int pos, int data) {
  int_array_resize(intArray, intArray->capacity + 1);
  for (int i = intArray->capacity - 2; i >= pos; i--) {
    intArray->address[i + 1] = intArray->address[i];
  }
  intArray->address[pos] = data;
}

void int_array_delete(IntArray * intArray, int pos) {
  for (int i = pos; i < intArray->capacity - 1; i++) {
    intArray->address[i] = intArray->address[i + 1];
  }
  int_array_resize(intArray, intArray->capacity - 1);
}
