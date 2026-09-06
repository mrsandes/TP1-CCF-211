#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemon/pokemon.h"

typedef struct {
  Pokemon pokemon;
  Pokelista *prox;
} Pokelista;

Pokelista* pokelista_cria();

Pokelista* pokelista_insere(Pokelista *pokelista, Pokemon pokemon);

Pokelista* pokelista_retira(Pokelista *pokelista, Pokemon pokemon);

Pokelista* pokelista_busca(Pokelista *pokelista, Pokemon pokemon);

void pokelista_imprime(Pokelista *pokelista);

int pokelista_vazia(Pokelista *pokelista);

void pokelista_libera(Pokelista *pokelista);

int pokelista_tamanho(Pokelista *pokelista);

#endif