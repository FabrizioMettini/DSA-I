#include <assert.h>
#include <math.h>

#define EPSILON 0.0001

void bubble_sort(float array[], int length) {
  for (int iter = 0; iter < length - 1; iter++) {
    for (int i = 0; i < length - iter - 1; i++) {
      if (array[i] > array[i + 1]) {
        float aux = array[i];
        array[i] = array[i + 1];
        array[i + 1] = aux;
      }
    }
  }
}

float median(float *array, int length) {
  if (length % 2 != 0) {
    return array[length/2];
  } else {
    return (array[length/2] + array[length/2 - 1]) / 2;
  }
}

int main() {
  float arr1[] = {-1.0, 2.2, 2.9, 3.1, 3.5};
  float arr2[] = {-1.0, 2.2, 2.9, 3.1};
  assert(fabs(median(arr1, 5) - 2.90) < EPSILON);
  assert(fabs(median(arr2, 4) - 2.55) < EPSILON);
  return 0;
}
