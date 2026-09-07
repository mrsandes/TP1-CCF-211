#include "centroDePesquisa.h"

void cp_init(CentroDePesquisa *cp) {
  Treinador tIncial;
  t_init(&tIncial, 0, "", 0);

  Coordenada lInicial;
  c_init(&lInicial, 0, 0);
  
  cp_set_treinador(cp, tIncial, TREINADOR1);
  cp_set_treinador(cp, tIncial, TREINADOR2);
  cp_set_pl_fugitivos(cp, pl_cria());
  cp_set_pl_recuperados(cp, pl_cria());
  cp_set_localizacao(cp, lInicial);
}

void cp_insere_registros(CentroDePesquisa *cp, char inputFile[]) {
  FILE *file = fopen(inputFile, "r");
  if (file == NULL) {
    printf("Erro: Nao foi possivel abrir o arquivo '%s'.\n", inputFile);
    return;
  }

  Treinador t1, t2;
  int numPokemons;
  Pokemon p;

  fscanf(file, "%s %d", t1.nome, &t1.numPokebolas);
  fscanf(file, "%s %d", t2.nome, &t2.numPokebolas);

  cp_set_treinador(cp, t1, 0);
  cp_set_treinador(cp, t2, 1);

  fscanf(file, "%d", &numPokemons);

  for (int i = 0; i < numPokemons; i++) {
    fscanf(file, "%d %s %s %f %f", &p.numPokedex, p.nome, p.tipo, &p.localizacao.x, &p.localizacao.y);

    p_init(&p, i, p.numPokedex, p.nome, p.tipo, p.localizacao);

    cp_set_pl_fugitivos(cp, pl_insere(cp->pl_fugitivos, p));
  }  
}

void cp_remove_fugitivo(CentroDePesquisa *cp, Pokemon p) {
  cp_set_pl_fugitivos(cp, pl_retira(cp_get_pl_fugitivos(cp), p));
}

void cp_imprime_fugitivos(CentroDePesquisa *cp) {
  pl_imprime(cp->pl_fugitivos);
}

void cp_recebe_pokemons(CentroDePesquisa *cp, int id) {
  Pokelista *pRecebidos = t_get_pl(cp_get_treinador(cp, id));

  while (pRecebidos != NULL) {
    cp_set_pl_recuperados(cp, pl_insere(cp_get_pl_recuperados(cp), pRecebidos->pokemon));

    cp_remove_fugitivo(cp, pRecebidos->pokemon);

    pRecebidos = pRecebidos->prox;
  }

  pl_libera(t_get_pl(cp_get_treinador(cp, id)));

  t_set_pl(cp_get_treinador(cp, id), pl_cria());
}

int cp_recarrega_pokebolas(CentroDePesquisa *cp, int id) {
  int newPokebolas = (rand() % 20) + 1;
  t_set_numPokebolas(cp_get_treinador(cp, id), newPokebolas);
  t_set_localizacao(cp_get_treinador(cp, id), cp_get_localizacao(cp));

  return newPokebolas;
}

Treinador* cp_get_treinador(CentroDePesquisa *cp, int id) {
  return &cp->treinadores[id];
}

Pokelista* cp_get_pl_fugitivos(CentroDePesquisa *cp) {
  return cp->pl_fugitivos;
}

Pokelista* cp_get_pl_recuperados(CentroDePesquisa *cp) {
  return cp->pl_recuperados;
}

Coordenada cp_get_localizacao(CentroDePesquisa *cp) {
  return cp->localizacao;
}

void cp_set_treinador(CentroDePesquisa *cp, Treinador t, int id) {
  t_init(&cp->treinadores[id], id, t.nome, t.numPokebolas);
}

void cp_set_pl_fugitivos(CentroDePesquisa *cp, Pokelista *pl) {
  cp->pl_fugitivos = pl;
}

void cp_set_pl_recuperados(CentroDePesquisa *cp, Pokelista *pl) {
  cp->pl_recuperados = pl;
}

void cp_set_localizacao(CentroDePesquisa *cp, Coordenada l) {
  cp->localizacao = l;
}