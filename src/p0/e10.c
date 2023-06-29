#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copiar_cadena(char *cad, int longitud) {
  char *a = malloc(sizeof(char) * longitud);
  strcpy(a, cad);               // fixed
  return a;
}

int main() {
  char a[10] = "hola";
  char *b = copiar_cadena(a, 10);
  printf("%s %s\n", a, b);
  b[0] = 's';
  printf("%s %s\n", a, b);
  free(b);                      // fixed
  return 0;
}

// original output:
// hola hola
// sola sola

// fixed output:
// hola hola
// hola sola
