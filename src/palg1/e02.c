#include <assert.h>

int f_exp(int b, int n) {
  int res = 1;
  for (int i = 0; i < n; i++) {
    res *= b;
  }
  return res;
}

int main() {
  assert(f_exp(5, 0) == 1);
  assert(f_exp(5, 1) == 5);
  assert(f_exp(5, 9) == 1953125);
  return 0;
}