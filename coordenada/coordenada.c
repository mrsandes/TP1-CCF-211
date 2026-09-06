#include "coordenada.h"

float distancia(Coordenada c1, Coordenada c2) {
  return sqrt(pow(c1.x - c2.x) + pow(c1.y - c2.y));
}

