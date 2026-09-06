#ifndef CENTRODEPESQUISA_H
#define CENTRODEPESQUISA_H

#include "stdlib.h"
#include "time.h"
#include "treinador/treinador.h"

typedef struct {
  Treinador treinadores[2];
  Pokelista *pokelista_fugitivos;
  Pokelista *pokelista_recuperados;
  Coordenada localizacao;
} CentroDePesquisa;

#endif