#include <assert.h>

typedef int (*CompFunction)(int, int);
typedef enum { NO, YES } STRICT;

int greater(int n, int m) {
  return n > m;
}

int greater_or_equal(int n, int m) {
  return n >= m;
}

int peak_aux(int arr[], int n, CompFunction comp) {
  if (n == 1) {
    return 0;
  }

  if (comp(arr[0], arr[1])) {
    return 0;
  }

  for (int i = 1; i < n-1; i++) {
    if (comp(arr[i], arr[i-1]) && comp(arr[i], arr[i+1])) {
      return i;
    }
  }

  if (comp(arr[n-1], arr[n-2])) {
    return n-1;
  }

  return -1;
}


int peak(int arr[], int n, STRICT strict) {
  switch (strict) {
  case YES:
    return peak_aux(arr, n, greater);
  default:
    return peak_aux(arr, n, greater_or_equal);
  }
}

int main() {
  int arr1[] = {2, 2, 3, 5, 4};
  int arr2[] = {1, 2, 3, 4, 4};
  assert(peak(arr1, 5, NO) == 0);
  assert(peak(arr1, 5, YES) == 3);
  assert(peak(arr2, 5, NO) == 3);
  assert(peak(arr2, 5, YES) == -1);
  return 0;
}