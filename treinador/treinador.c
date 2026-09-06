#include "treinador.h"

void treinador_init(Treinador *treinador, int id, char nome[], int numPokebolas) {
  Coordenada localizacaoInicial;
  localizacaoInicial.x = 0;
  localizacaoInicial.y = 0;

  treinador_set_id(treinador, id);
  treinador_set_nome(treinador, nome);
  treinador_set_localizacao(treinador, localizacaoInicial);
  treinador_set_pokelista(treinador);
  treinador_set_numPokebolas(treinador, numPokebolas);
}

void treinador_move(Treinador *treinador, Coordenada newLocalizacao) {
  treinador_set_localizacao(treinador, newLocalizacao);
}

void treinador_captura(Treinador *treinador, Pokemon pokemon) {
  pokelista_insere(treinador->pokelista, pokemon);

  treinador->numPokebolas -= 1;
}

void treinador_retira_pokemon(Treinador *treinador, Pokemon pokemon) {
  pokelista_retira(treinador->pokelista, pokemon);
}

void treinador_imprime(Treinador *treinador) {

}

int treinador_get_id(Treinador *treinador) {
  return treinador->id;
}

char* treinador_get_nome(Treinador *treinador) {
  return treinador->nome;
}

Coordenada treinador_get_localizacao(Treinador *treinador) {
  return treinador->localizacao;
}

Pokelista* treinador_get_pokelista(Treinador *treinador) {
  return treinador->pokelista;
}

int treinador_get_numPokebolas(Treinador *treinador) {
  return treinador->numPokebolas;
}

void treinador_set_id(Treinador *treinador, int id) {
  treinador->id = id;
}

void treinador_set_nome(Treinador *treinador, char nome[]) {
  strcpy(treinador->nome, nome);
}

void treinador_set_localizacao(Treinador *treinador, Coordenada localizacao) {
  treinador->localizacao = localizacao;
}

void treinador_set_pokelista(Treinador *treinador) {
  treinador->pokelista = pokelista_cria();
}

void treinador_set_numPokebolas(Treinador *treinador, int numPokebolas) {
  treinador->numPokebolas = numPokebolas;
}