#include <assert.h>

int survivor_naive(int n) {
  int alive = n;
  int kill = 0;
  int death[n + 1];
  for (int i = 0; i <= n; i++) {
    death[i] = 0;
  }
  
  int i = 1;
  while (alive > 1) {
    if (!death[i]) {
      if (kill) {
        death[i] = 1;
        alive -= 1;
      }
      kill = !kill; 
    }
    i = (i + 1) % n;
  }
  
  i = 1;
  while (i <= n) {
    if (!death[i]) {
      return i;
    }
    i++;
  }
}

int ge_power_of_two(int n) {
  int k = 1;
  while (k < n) {
    k *= 2;
  }
  return k;
}

int survivor_math(int n) {
  int m = ge_power_of_two(n);
  if (m == n) {
    return 1;
  }
  return 2 * n - m + 1;
}

int main() {
  for (int i = 1; i <= 256; i++) {
    assert(survivor_naive(i) == survivor_math(i));
  }
  return 0;
}