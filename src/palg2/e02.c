#include <assert.h>
#include <stdio.h>

// If the array contains several elements equals to the element searched for, 
// then it is unspecified which element the function will return as the result. 
int binsearch(int a[], int len, int v) {
  int low = -1, high = len;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (a[mid] == v) {
      return mid;
    } else if (a[mid] < v) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return -1;
}

int main() {
  int arr[] = {0, 1, 3, 5, 7, 9};
  assert(binsearch(arr, 4, 3) == 2);
  assert(binsearch(arr, 4, 2) == -1);
  return 0;
}