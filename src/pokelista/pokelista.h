#ifndef POKELISTA_H
#define POKELISTA_H

#include <stdlib.h>
#include "../pokemon/pokemon.h"

typedef struct Pokelista {
    Pokemon pokemon;
    struct Pokelista *prox; 
} Pokelista;

Pokelista* pl_cria();

Pokelista* pl_insere(Pokelista *pl, Pokemon p);

Pokelista* pl_retira(Pokelista *pl, Pokemon p);

Pokelista* pl_busca(Pokelista *pl, Pokemon p);

void pl_imprime(Pokelista *pl);

int pl_vazia(Pokelista *pl);

void pl_libera(Pokelista *pl);

int pl_tamanho(Pokelista *pl);

#endif