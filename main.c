#include "coordenada/coordenada.h"
#include <stdio.h>

int main() {
  srand(time(NULL));

  Coordenada c1, c2;
  c1.x = 7;
  c1.y = 7;

  c2.x = 0;
  c2.y = 0;

  printf("%.2f", distancia(c1, c2));

  return 0;
}
