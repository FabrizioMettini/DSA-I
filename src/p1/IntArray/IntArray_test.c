#include <assert.h>
#include "IntArray.h"

int main() {
  IntArray *arr = int_array_create(5);

  for (int i = 0; i < arr->capacity; i++) {
    int_array_write(arr, i, i);
  }

  assert(int_array_read(arr, 3) == 3);
  assert(int_array_capacity(arr) == 5);

  int_array_resize(arr, 4);
  assert(int_array_capacity(arr) == 4);

  int_array_insert(arr, 2, 7);
  assert(int_array_read(arr, 2) == 7);
  assert(int_array_read(arr, 3) == 2);
  assert(int_array_read(arr, 4) == 3);

  int_array_delete(arr, 2);
  assert(int_array_read(arr, 2) == 2);
  assert(int_array_read(arr, 3) == 3);

  int_array_destroy(arr);
  return 0;
}
