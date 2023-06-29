#include <stdio.h>

struct pack3 {
  int a;
};

struct pack2 {
  int b;
  struct pack3 *next;
};

struct pack1 {
  int c;
  struct pack2 *next;
};

int main() {
  struct pack1 data1, *dataPtr;
  struct pack2 data2;
  struct pack3 data3;
  data1.c = 30;
  data2.b = 20;
  data3.a = 10;
  dataPtr = &data1;
  data1.next = &data2;
  data2.next = &data3;
  return 0;
}

// Expresion | Correcta | Valor
// |:---|:---|:---|
// data1.c | Si | 30 
// dataPtr→c | Si | 30
// dataPtr.c | No | -
// data1.next→b | Si | 20
// dataPtr→next→b | Si | 20
// dataPtr.next.b | No | -
// dataPtr→next.b | No | -
// (*(dataPtr→next)).b | Si | 20
// data1.next→next→a | Si | 10
// dataPtr→next→next.a | No | -
// dataPtr→next→next→a | Si | 10
// dataPtr→next→a | No | -
// dataPtr→next→next→b | No | -
