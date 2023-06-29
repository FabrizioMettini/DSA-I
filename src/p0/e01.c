#include <stdio.h>

int main() {
  int a, b;
  printf("address of a: %p\n", &a);
  printf("address of b: %p\n", &b);

  char arr[6] = "hello\n";
  for (int i = 0; i < 6; i++) {
    printf("address of arr[%i]: %p\n", i, arr + i);
  }

  return 0;
}
