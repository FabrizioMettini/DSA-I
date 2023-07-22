#include <assert.h>
#include <stdio.h>

void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int insertion_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i-1; j >= 0; j--) {
      if (a[j] > a[j+1]) {
        swap(a, j, j+1);
      } else {
        break;
      }
    } 
  } 
}

void array_move_element(int a[], int i, int j) {
  int tmp = a[i];
  for (int k = i; k > j; k--) {
    a[k] = a[k-1];
  }
  a[j] = tmp;
}

int insertion_sort_optimized(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int j;
    for (j = i-1; j >= 0; j--) {
      if (a[j] < a[i]) {
        break;
      }
    } 
    array_move_element(a, i, j+1);
  } 
}

int main() {
  int arr[] = {4, 2, 3, 1};
  insertion_sort_optimized(arr, 4);
  printf("Sorted: ");
  for (int i = 0; i < 4; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
  return 0;
}