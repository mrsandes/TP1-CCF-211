#include "pokemon.h"

void p_init(Pokemon *p, int id, int numPokedex, char nome[], char tipo[], Coordenada localizacao) {
  p_set_id(p, id);
  p_set_numPokedex(p, numPokedex);
  p_set_nome(p, nome);
  p_set_tipo(p, tipo);
  p_set_localizacao(p, localizacao);
}

void p_imprime(Pokemon *p) {
  printf("%d %s\n", p->numPokedex, p->nome);
}

int p_get_id(Pokemon *p) {
  return p->id;
}

int p_get_numPokedex(Pokemon *p) {
  return p->numPokedex;
}

char* p_get_nome(Pokemon *p) {
  return p->nome;
}

char* p_get_tipo(Pokemon *p) {
  return p->tipo;
}

Coordenada p_get_localizacao(Pokemon *p) {
  return p->localizacao;
}

int p_get_localizacao_x(Pokemon *p) {
  return p->localizacao.x;
}

int p_get_localizacao_y(Pokemon *p) {
  return p->localizacao.y;
}

void p_set_id(Pokemon *p, int id) {
  p->id = id;
}

void p_set_numPokedex(Pokemon *p, int numPokedex) {
  p->numPokedex = numPokedex;
}

void p_set_nome(Pokemon *p, char nome[]) {
  strcpy(p->nome, nome);
}

void p_set_tipo(Pokemon *p, char tipo[]) {
  strcpy(p->tipo, tipo);
}

void p_set_localizacao(Pokemon *p, Coordenada l) {
  p->localizacao = l;
}