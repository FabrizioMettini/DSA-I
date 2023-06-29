#include <assert.h>

struct Punto {
  int x;
  int y;
};

struct Punto medio(struct Punto a, struct Punto b) {
  return (struct Punto) { (a.x + b.x) / 2, (a.y + b.y) / 2 };
}

int main() {
  struct Punto p1 = { 0, 2 };
  struct Punto p2 = { 2, 0 };
  struct Punto p3 = medio(p1, p2);
  assert(p3.x == 1);
  assert(p3.y == 1);
  return 0;
}
