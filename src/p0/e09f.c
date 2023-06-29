#include <stdio.h>

int *direccion_local(int x) {
  return &x;
}

int main() {
  int *ptr = NULL;
  ptr = direccion_local(2);
  printf("%d\n", *ptr);
  return 0;
}

// ERROR:
// returns address of local variable
