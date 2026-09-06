#include "coordenada.h"

float coordenada_distancia(Coordenada c1, Coordenada c2) {
  return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}