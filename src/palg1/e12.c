#include <assert.h>

// Time Complexity: O(n)
float peval(float c[], int n, float x) {
  float sum = c[0];
  for (int i = 1; i <= n; i++) {
    sum += c[i] * x;
    x *= x;
  }
  return sum;
}

int main() {
  float c[] = {1, 2, 3};
  assert(peval(c, 2, 5) == 86);
  return 0;
}