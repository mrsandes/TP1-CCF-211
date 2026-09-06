#include "centroDePesquisa.h"

void centroDePesquisa_init(CentroDePesquisa *centroDePesquisa, char inputFile[]) {
  Treinador treinadorInicial;
  treinador_init(&treinadorInicial, 0, NULL, 0);

  Coordenada localizacaoInicial;
  localizacaoInicial.x = 0;
  localizacaoInicial.y = 0;
  
  centroDePesquisa_set_treinador(centroDePesquisa, treinadorInicial, 0);
  centroDePesquisa_set_treinador(centroDePesquisa, treinadorInicial, 1);
  centroDePesquisa_set_pokelista_fugitivos(centroDePesquisa);
  centroDePesquisa_set_pokelista_recuperados(centroDePesquisa);
  centroDePesquisa_set_localizacao(centroDePesquisa, localizacaoInicial);
}

void centroDePesquisa_insere_registros(CentroDePesquisa *centroDePesquisa, char inputFile[]) {
  FILE *file = fopen(inputFile, "r");

  Treinador t0, t1;
  int numPokemons;
  Pokemon p;

  fscanf(file, "%s %d", &t0.nome, &t0.numPokebolas);
  fscanf(file, "%s %d", &t1.nome, &t1.numPokebolas);

  centroDePesquisa_set_treinador(centroDePesquisa, t0, 0);
  centroDePesquisa_set_treinador(centroDePesquisa, t1, 1);

  fscanf(file, "%d", &numPokemons);

  for (int i = 0; i < numPokemons; i++) {
    fscanf(file, "%d %s %s %d %d", &p.numPokedex, &p.nome, &p.tipo, &p.localizacao.x, &p.localizacao.y);

    pokemon_init(&p, i, p.numPokedex, p.nome, p.tipo, p.localizacao);

    pokelista_insere(centroDePesquisa->pokelista_fugitivos, p);
  }  
}

void centroDePesquisa_remove_fugitivo(CentroDePesquisa *centroDePesquisa, Pokemon pokemon) {
  pokelista_retira(centroDePesquisa->pokelista_fugitivos, pokemon);
}

void centroDePesquisa_imprime_fugitivos(CentroDePesquisa *centroDePesquisa) {
  pokelista_imprime(centroDePesquisa->pokelista_fugitivos);
}

void centroDePesquisa_recebe_pokemons(CentroDePesquisa *centroDePesquisa, int id) {
  Pokelista *pokemonsRecebidos = pokelista_cria();

  pokemonsRecebidos = treinador_get_pokelista(&centroDePesquisa->treinadores[id]);

  for (int i = 0; i < pokelista_tamanho(pokemonsRecebidos); i++) {
    pokelista_insere(centroDePesquisa->pokelista_recuperados, pokemonsRecebidos->pokemon);
    centroDePesquisa_remove_fugitivo(centroDePesquisa->pokelista_fugitivos, pokemonsRecebidos->pokemon);

    pokemonsRecebidos = pokemonsRecebidos->prox;
  }

  pokelista_libera(centroDePesquisa->treinadores[id].pokelista);  
}

void centroDePesquisa_recarrega_pokebolas(CentroDePesquisa *centroDePesquisa, int id) {
  int newPokebolas = (rand() % 20) + 1;
  treinador_set_numPokebolas(&centroDePesquisa->treinadores[id], newPokebolas);
}

Treinador centroDePesquisa_get_treinador(CentroDePesquisa *centroDePesquisa, int id) {
  return centroDePesquisa->treinadores[id];
}

Pokelista* centroDePesquisa_get_pokelista_fugitivos(CentroDePesquisa *centroDePesquisa) {
  return centroDePesquisa->pokelista_fugitivos;
}

Pokelista* centroDePesquisa_get_pokelista_recuperados(CentroDePesquisa *centroDePesquisa) {
  return centroDePesquisa->pokelista_recuperados;
}

Coordenada centroDePesquisa_get_localizacao(CentroDePesquisa *centroDePesquisa) {
  return centroDePesquisa->localizacao;
}

void centroDePesquisa_set_treinador(CentroDePesquisa *centroDePesquisa, Treinador treinador, int id) {
  treinador_init(&centroDePesquisa->treinadores[id], id, treinador.nome, treinador.numPokebolas);
}

void centroDePesquisa_set_pokelista_fugitivos(CentroDePesquisa *centroDePesquisa) {
  centroDePesquisa->pokelista_fugitivos = pokelista_cria();
}

void centroDePesquisa_set_pokelista_recuperados(CentroDePesquisa *centroDePesquisa) {
  centroDePesquisa->pokelista_recuperados = pokelista_cria();
}

void centroDePesquisa_set_localizacao(CentroDePesquisa *centroDePesquisa, Coordenada localizacao) {
  centroDePesquisa->localizacao = localizacao;
}