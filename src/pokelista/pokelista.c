#include "pokelista.h"

Pokelista* pl_cria() {
	return NULL;
}

Pokelista* pl_insere(Pokelista *pl, Pokemon p) {
	Pokelista *novo = (Pokelista*) malloc(sizeof(Pokelista));
	if (novo == NULL) {
		return pl;
	} 

	novo->pokemon = p;
	novo->prox = NULL;

	if (pl == NULL) {
		return novo;
	}

	Pokelista *atual = pl;
	while (atual->prox != NULL) {
		atual = atual->prox;
	}

	atual->prox = novo;

	return pl;
}

Pokelista* pl_retira(Pokelista *pl, Pokemon p) {
	Pokelista *aux = pl;
	Pokelista *ant = NULL;

	while (aux != NULL && aux->pokemon.id != p.id) {
		ant = aux;
		aux = aux->prox;
	}

	if (aux == NULL) {
		printf("Elemento não encontrado\n");
		return pl;
	}

	if (ant == NULL) {
		pl = aux->prox;
	}

	else {
		ant->prox = aux->prox;
	}

	free(aux);
	return pl;
}

Pokelista* pl_busca(Pokelista *pl, Pokemon p) {
	Pokelista *aux;

	for (aux = pl; aux != NULL; aux = aux->prox) {
		if (aux->pokemon.id == p.id) {
			return aux;
		}
	}

	return NULL;
}

void pl_imprime(Pokelista *pl) {
	Pokelista *aux;

	for (aux = pl; aux != NULL; aux = aux->prox) {
		printf("Pokemon: ");
		p_imprime(&aux->pokemon);
	}
}

int pl_vazia(Pokelista *pl) {
	if (pl == NULL)
		return 1;

	else
		return 0;
}

void pl_libera(Pokelista *pl) {
	Pokelista *aux = pl;

	while (aux != NULL) {
		Pokelista *temp = aux->prox;
		free(aux);
		aux = temp;
	}

	pl = NULL;
}

int pl_tamanho(Pokelista *pl) {
	Pokelista *aux;
	int tam = 0;

	for (aux = pl; aux != NULL; aux = aux->prox) {
		tam++;		
	}
	
	return tam;	
}