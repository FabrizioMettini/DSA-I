#include <stdio.h>

int main() {
  char *ptr = "hola mundo";
  ptr[0] = 's';
  printf("%s\n", ptr);
  return 0;
}

// the output is
// Segmentation fault
