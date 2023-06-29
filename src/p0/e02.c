#include <assert.h>

void set_first(int arr[]) {
  *arr = 0;
}

int main() {
  int arr[5] = { 1, 2, 3, 4, 5 };
  set_first(arr);
  assert(arr[0] == 0);
  return 0;
}

// This happens because the argument of set_first is a pointer to the beginning of the memory block of the array.
// What is copied is a memory address.
