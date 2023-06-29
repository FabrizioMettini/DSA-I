#include <stdio.h>

void aumentar_punteros(int *x, int *y, int z) {
  *x = *x + 2;
  *y = *y + 5;
  z = z + 4;
}

int main() {
  int x, y, z;
  x = 3;
  y = 10;
  z = 15;
  aumentar_punteros(&x, &y, z);
  printf("%d %d %d", x, y, z);
  return 0;
}

// the output is 5 15 15
