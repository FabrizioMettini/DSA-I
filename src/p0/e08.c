#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef void (*VisitorFunc)(int);

// a.
int apply(int (*f)(int n), int a) {
  return f(a);
}

// b.
void apply_in(int (*f)(int n), int *a) {
  *a = f(*a);
}

// c.
void recorre(VisitorFunc f, int arr[], int n) {
  for (int i = 0; i < n; i++) {
    f(arr[i]);
  }
}

// d.
int sucesor(int n) {
  return n + 1;
}

void imprimir(int n) {
  printf("%d\n", n);
}

int main() {
  int a = 5;
  assert(apply(sucesor, a) == 6);

  apply_in(sucesor, &a);
  assert(a == 6);

  int arr[5] = { 1, 2, 3, 4, 5 };
  recorre(imprimir, arr, 5);

  return 0;
}
