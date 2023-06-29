#include <stdlib.h>

int main() {
  int *arr = malloc(sizeof(int) * 4);
  free(arr);
  free(arr);
  return 0;
}

// ERROR: 
// free(): double free detected in tcache 2
// Aborted (core dumped)
