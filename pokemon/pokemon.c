#include "pokemon.h"

void pokemon_init(Pokemon *pokemon, int id, int numPokedex, char nome[], char tipo[], Coordenada localizacao) {
  pokemon_set_id(pokemon, id);
  pokemon_set_numPokedex(pokemon, numPokedex);
  pokemon_set_nome(pokemon, nome);
  pokemon_set_tipo(pokemon, tipo);
  pokemon_set_localizacao(pokemon, localizacao);
}

void pokemon_imprime(Pokemon *pokemon) {

}

int pokemon_get_id(Pokemon *pokemon) {
  return pokemon->id;
}

int pokemon_get_numPokedex(Pokemon *pokemon) {
  return pokemon->numPokedex;
}

char* pokemon_get_nome(Pokemon *pokemon) {
  return pokemon->nome;
}

char* pokemon_get_tipo(Pokemon *pokemon) {
  return pokemon->tipo;
}

Coordenada pokemon_get_localizacao(Pokemon *pokemon) {
  return pokemon->localizacao;
}

void pokemon_set_id(Pokemon *pokemon, int id) {
  pokemon->id = id;
}

void pokemon_set_numPokedex(Pokemon *pokemon, int numPokedex) {
  pokemon->numPokedex = numPokedex;
}

void pokemon_set_nome(Pokemon *pokemon, int nome) {
  strcpy(pokemon->nome, nome);
}

void pokemon_set_tipo(Pokemon *pokemon, int tipo) {
  strcpy(pokemon->tipo, tipo);
}

void pokemon_set_localizacao(Pokemon *pokemon, Coordenada localizacao) {
  pokemon->localizacao = localizacao;
}