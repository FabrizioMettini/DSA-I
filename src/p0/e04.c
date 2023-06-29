#include <assert.h>

void swap(int *n, int *m) {
  int temp = *n;
  *n = *m;
  *m = temp;
}

int main() {
  int a = 3;
  int b = 2;

  swap(&a, &b);

  assert(a == 2);
  assert(b == 3);

  return 0;
}
