#include <stdio.h>
#define PRINTARRAY(arr, n) for (int i= 0; i < n; i++) printf("%d\n", arr[i]);

int main() {
  int array[5] = {2, 3, 5, 7, 11};
  PRINTARRAY(array, 5);
  return 0;
}