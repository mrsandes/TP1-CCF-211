#ifndef POKEMON_H
#define POKEMON_H

#include <string.h>
#include <stdio.h>
#include "coordenada/coordenada.h"
#define MAX_TAM_STRING 50

typedef struct {
  int id;
  int numPokedex;
  char nome[MAX_TAM_STRING];
  char tipo[MAX_TAM_STRING];
  Coordenada localizacao;
} Pokemon;

void pokemon_init(Pokemon *pokemon, int id, int numPokedex, char nome[], char tipo[], Coordenada localizacao);

void pokemon_imprime(Pokemon *pokemon);

int pokemon_get_id(Pokemon *pokemon);

int pokemon_get_numPokedex(Pokemon *pokemon);

char* pokemon_get_nome(Pokemon *pokemon);

char* pokemon_get_tipo(Pokemon *pokemon);

Coordenada pokemon_get_localizacao(Pokemon *pokemon);

void pokemon_set_id(Pokemon *pokemon, int id);

void pokemon_set_numPokedex(Pokemon *pokemon, int numPokedex);

void pokemon_set_nome(Pokemon *pokemon, int nome);

void pokemon_set_tipo(Pokemon *pokemon, int tipo);

void pokemon_set_localizacao(Pokemon *pokemon, Coordenada localizacao);

#endif
