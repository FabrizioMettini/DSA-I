#include <stdio.h>
#define PI 3.14159
#define ESFERA_VOLUMEN(r) (4/3.0 * PI * (r) * (r) * (r))

int main() {
  for (int i = 1; i <= 10; i++) {
      printf("radio: %d\t volumen %f\n", i, ESFERA_VOLUMEN(i));
  }
  return 0;
}
