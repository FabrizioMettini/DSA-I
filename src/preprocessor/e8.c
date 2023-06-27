#include <stdio.h>

int sum(int array[], int n) {
  int s = 0;
  for(int x = 0; x < n; x++)
      s += array[x];
  return s;
}

#define SUMARRAY(a, b) sum(a, b)

int main() {
  int array[5] = {2, 3, 5, 7, 11};
  printf("Suma: %d\n", SUMARRAY(array, 5));
  return 0;
}