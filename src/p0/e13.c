#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a.
enum Palo { ORO, COPA, BASTO, ESPADA };

struct Carta {
  enum Palo palo;
  int numero;
};

void mostrarCarta(struct Carta carta) {
  printf("Palo: %d Número: %d\n", carta.palo, carta.numero);
}

// b.
struct Mazo {
  struct Carta cartas[48];
};

void mostrarMazo(struct Mazo mazo) {
  for (int i = 0; i < 48; i++) {
    mostrarCarta(mazo.cartas[i]);
  }
}

//c.
void llenar(struct Mazo *mazo) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 12; j++) {
      mazo->cartas[i * 12 + j] = (struct Carta) { i, j + 1 };
    }
  }
}

// d.
struct Carta azar(struct Mazo mazo) {
  srand(time(NULL));
  int r = rand() % 47;
  return mazo.cartas[r];
}

int main() {
  struct Mazo mazo;
  llenar(&mazo);
  struct Carta cualq = azar(mazo);
  mostrarCarta(cualq);
  return 0;
}
