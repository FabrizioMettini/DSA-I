#include <assert.h>

void set_in(int *n) {
  if (*n) {
    *n = 1;
  } else {
    *n = 0;
  }
}

int main() {
  int a = 2;
  int b = 0;

  set_in(&a);
  set_in(&b);

  assert(a == 1);
  assert(b == 0);

  return 0;
}
