#ifndef TREINADOR_H
#define TREINADOR_H

#include "coordenada/coordenada.h"
#include "pokelista/pokelista.h"

typedef struct {
  int id;
  char nome[MAX_TAM_STRING];
  Coordenada localizacao;
  Pokelista *pokelista;
  int numPokebolas;
} Treinador;

void treinador_init(Treinador *treinador, int id, char nome[], int numPokebolas);

void treinador_move(Treinador *treinador, Coordenada newLocalizacao);

void treinador_captura(Treinador *treinador, Pokemon pokemon);

void treinador_retira_pokemon(Treinador *treinador, Pokemon pokemon);

void treinador_imprime(Treinador *treinador);

int treinador_get_id(Treinador *treinador);

char* treinador_get_nome(Treinador *treinador);

Coordenada treinador_get_localizacao(Treinador *treinador);

Pokelista* treinador_get_pokelista(Treinador *treinador);

int treinador_get_numPokebolas(Treinador *treinador);

void treinador_set_id(Treinador *treinador, int id);

void treinador_set_nome(Treinador *treinador, char nome[]);

void treinador_set_localizacao(Treinador *treinador, Coordenada localizacao);

void treinador_set_pokelista(Treinador *treinador);

void treinador_set_numPokebolas(Treinador *treinador, int numPokebolas);

#endif