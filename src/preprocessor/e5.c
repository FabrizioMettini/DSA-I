#include <stdio.h>
#define MININUM2(a, b) ((a) < (b) ? (a) : (b))
#define MININUM3(a, b, c) MININUM2(MININUM2(a, b), c)

int main() {
  double a, b, c;

  printf("Ingrese el primer número: ");
  scanf("%lf", &a);

  printf("Ingrese el segundo número: ");
  scanf("%lf", &b);

  printf("Ingrese el tercer número: ");
  scanf("%lf", &c);

  printf("El mínimo es: %lf\n", MININUM3(a, b, c));

  return 0;
}