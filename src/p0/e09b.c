#include <stdio.h>

int main() {
  int *punt;
  int x = 7, y = 5;
  punt = &x;
  x = 4;
  punt = &y;
  printf("%d %d", *punt, x);
  return 0;
}

// the output is 5 4
