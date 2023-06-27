#include <stdio.h>
#define MININUM2(a, b) ((a) < (b) ? (a) : (b))

int main() {
  double a, b;

  printf("Ingrese el primer número: ");
  scanf("%lf", &a);

  printf("Ingrese el segundo número: ");
  scanf("%lf", &b);

  printf("El mínimo es: %lf\n", MININUM2(a, b));

  return 0;
}