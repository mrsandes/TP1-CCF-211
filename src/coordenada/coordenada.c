#include "coordenada.h"

float c_distancia(Coordenada c1, Coordenada c2) {
  return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

void c_init(Coordenada *c, int x, int y) {
  c->x = x;
  c->y = y;
}