#include "treinador.h"

void t_init(Treinador *t, int id, char nome[], int numPokebolas) {
  Coordenada lInicial;
  c_init(&lInicial, 0, 0);
  
  t_set_id(t, id);
  t_set_nome(t, nome);
  t_set_localizacao(t, lInicial);
  t_set_pl(t, pl_cria());
  t_set_numPokebolas(t, numPokebolas);
}

void t_move(Treinador *t, Coordenada newLocalizacao) {
  t_set_localizacao(t, newLocalizacao);
}

void t_captura(Treinador *t, Pokemon p) {
  t_set_pl(t, pl_insere(t->pokelista, p));

  t->numPokebolas -= 1;
}

void t_retira_pokemon(Treinador *t, Pokemon p) {
  t_set_pl(t, pl_retira(t->pokelista, p));
}

void t_imprime(Treinador *t) {
  printf("Treinador(a) %s: posicao (%d,%d) | Pokebolas: %d\n", 
    t_get_nome(t), 
    t_get_localizacao_x(t), 
    t_get_localizacao_y(t),
    t_get_numPokebolas(t));
}

int t_get_id(Treinador *t) {
  return t->id;
}

char* t_get_nome(Treinador *t) {
  return t->nome;
}

Coordenada t_get_localizacao(Treinador *t) {
  return t->localizacao;
}

int t_get_localizacao_x(Treinador *t) {
  return t->localizacao.x;
}

int t_get_localizacao_y(Treinador *t) {
  return t->localizacao.y;
}

Pokelista* t_get_pl(Treinador *t) {
  return t->pokelista;
}

int t_get_numPokebolas(Treinador *t) {
  return t->numPokebolas;
}

void t_set_id(Treinador *t, int id) {
  t->id = id;
}

void t_set_nome(Treinador *t, char nome[]) {
  strcpy(t->nome, nome);
}

void t_set_localizacao(Treinador *t, Coordenada l) {
  t->localizacao = l;
}

void t_set_pl(Treinador *t, Pokelista *pl) {
  t->pokelista = pl;
}

void t_set_numPokebolas(Treinador *t, int numPokebolas) {
  t->numPokebolas = numPokebolas;
}