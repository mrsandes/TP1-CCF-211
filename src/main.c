#include "centroDePesquisa/centroDePesquisa.h"

int main() {
  CentroDePesquisa cp;
  FILE *output = fopen("relatorio.txt", "w");
  int numFugitivos, idEscolhido;
  float distanciaT1, distanciaT2 ;
  Treinador *tEscolhido;
  Pokelista *aux;

  cp_init(&cp);

  cp_insere_registros(&cp, "testes/teste1.txt");

  numFugitivos = pl_tamanho(cp.pl_fugitivos);

  printf("========================================\n");
  printf("            INICIO DA MISSAO            \n");
  printf("========================================\n\n"); 

  t_imprime(&cp.treinadores[TREINADOR1]);
  t_imprime(&cp.treinadores[TREINADOR2]);

  printf("\nPokemons fugitivos a serem resgatados: %d\n\n", numFugitivos);

  for (aux = cp_get_pl_fugitivos(&cp); aux != NULL; aux = aux->prox) {
    distanciaT1 = c_distancia(p_get_localizacao(&aux->pokemon), t_get_localizacao(&cp.treinadores[TREINADOR1]));
    distanciaT2 = c_distancia(p_get_localizacao(&aux->pokemon), t_get_localizacao(&cp.treinadores[TREINADOR2]));
    idEscolhido = (distanciaT1 <= distanciaT2) ? TREINADOR1 : TREINADOR2;
    tEscolhido = cp_get_treinador(&cp, idEscolhido);

    printf("----------------------------------------\n");
    printf("Pokemon Alvo: %s\n", p_get_nome(&aux->pokemon));
    printf("Localizacao: (%d,%d)\n\n", p_get_localizacao_x(&aux->pokemon), p_get_localizacao_y(&aux->pokemon));
  
    printf("Distancia Treinador(a) %s: %.2f\n", t_get_nome(cp_get_treinador(&cp, TREINADOR1)), distanciaT1);

    printf("Distancia Treinador(a) %s: %.2f\n\n", t_get_nome(cp_get_treinador(&cp, TREINADOR2)), distanciaT2);

    printf("Missao atribuida ao Treinador(a) %s\n\n", tEscolhido->nome);

    printf("Treinador(a) %s se movimentou para (%d,%d)\n", tEscolhido->nome, p_get_localizacao_x(&aux->pokemon), p_get_localizacao_y(&aux->pokemon));

    t_set_localizacao(tEscolhido, p_get_localizacao(&aux->pokemon));
    t_captura(tEscolhido, aux->pokemon);

    printf("%s capturado com sucesso!\n\n", p_get_nome(&aux->pokemon));

    printf("Pokebolas restantes para o Treinador(a) %s: %d\n\n", tEscolhido->nome, tEscolhido->numPokebolas);

    if (t_get_numPokebolas(tEscolhido) == 0 && aux->prox != NULL) {
      printf("========================================\n");
      printf("      Treinador(a) %s SEM POKEBOLAS   \n", tEscolhido->nome);
      printf("========================================\n\n");

      printf("Treinador(a) %s retorna ao Centro de Pesquisa\n\n", tEscolhido->nome);

      printf("Entregando Pokemon ao Centro de Pesquisa\n\n");
      cp_recebe_pokemons(&cp, idEscolhido);

      printf("Treinador(a) %s recebeu %d Pokebolas\n\n", tEscolhido->nome, cp_recarrega_pokebolas(&cp, idEscolhido));
    }
  }

  printf("========================================\n");
  printf("    Todos Pokemons foram resgatados     \n");
  printf("========================================\n\n");

  printf("Ambos treinadores retornam ao Centro de Pesquisa\n\n");
  printf("Treinador(a) %s devolve os Pokemon\n\n", t_get_nome(cp_get_treinador(&cp, TREINADOR1)));
  printf("Treinador(a) %s devolve os Pokemon\n\n", t_get_nome(cp_get_treinador(&cp, TREINADOR2)));

  printf("========================================\n");
  printf("            MISSAO CONCLUIDA            \n");
  printf("========================================\n");

  cp_recebe_pokemons(&cp, TREINADOR1);
  cp_recebe_pokemons(&cp, TREINADOR2);

  fprintf(output, "Pokemon recuperados:\n");
  
  for (aux = cp_get_pl_recuperados(&cp); aux != NULL; aux = aux->prox) {
    fprintf(output, "%d %s\n", p_get_numPokedex(&aux->pokemon), p_get_nome(&aux->pokemon));
  }
   
  return SUCESSO;
}
