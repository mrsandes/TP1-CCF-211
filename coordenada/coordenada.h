#ifndef COORDENADA_H
#define COORDENADA_H

#include <math.h>

typedef struct {
  float x;
  float y;
} Coordenada;

float coordenada_distancia(Coordenada c1, Coordenada c2);

#endif