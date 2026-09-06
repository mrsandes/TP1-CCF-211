#include "pokelista.h"

Pokelista* Pokelista_cria() {
	return NULL;
}

Pokelista* Pokelista_insere(Pokelista *pokelista, Pokemon pokemon) {
	Pokelista *novo = (Pokelista*)malloc(sizeof(Pokelista));

	novo->pokemon = pokemon;
	novo->prox = pokelista;

	return novo;
}

Pokelista* Pokelista_retira(Pokelista *pokelista, Pokemon pokemon) {
	Pokelista *p = pokelista;
	Pokelista *ant = NULL;

	while (p != NULL && p->pokemon.id != pokemon.id) {
		ant = p;
		p = p->prox;
	}

	if (p == NULL) {
		printf("Elemento não encontrado\n");
		return pokelista;
	}

	if (ant == NULL) {
		pokelista = p->prox;
	}

	else {
		ant->prox = p->prox;
	}

	free(p);
	return pokelista;
}

Pokelista* Pokelista_busca(Pokelista *pokelista, Pokemon pokemon) {
	Pokelista *p;

	for (p = pokelista; p != NULL; p = p->prox) {
		if (p->pokemon.id == pokemon.id) {
			return p;
		}
	}

	if (p == NULL) {
		return NULL;
	}
}

void Pokelista_imprime(Pokelista *pokelista) {
	Pokelista *p;

	for (p = pokelista; p != NULL; p = p->prox) {
		printf("Pokemon: %d\n", p->pokemon.numPokedex);
	}
}

int Pokelista_vazia(Pokelista *pokelista) {
	if (pokelista == NULL)
		return 1;

	else
		return 0;
}

void Pokelista_libera(Pokelista *pokelista) {
	Pokelista *p = pokelista;

	while (p != NULL) {
		Pokelista *t = p->prox;
		free(p);
		p = t;
	}
}

int pokelista_tamanho(Pokelista *pokelista) {
	Pokelista *p;
	int tam = 0;

	for (p = pokelista; p != NULL; p = p->prox) {
		tam++;		
	}
	
	return tam;	
}