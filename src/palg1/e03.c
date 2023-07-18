#include <assert.h>

int arr_max(int arr[], int n) {
  int imax = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > arr[imax]) {
      imax = i;
    }
  }
  return imax;  
}

int main() {
  int arr[] = {3, 5, 2, 8, 4, 9, 1, 4, 7};
  assert(arr_max(arr, 9) == 5);
  return 0;
}
