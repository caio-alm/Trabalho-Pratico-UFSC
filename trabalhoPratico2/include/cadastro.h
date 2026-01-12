#ifndef CADASTRO_H
#define CADASTRO_H

#include <stdbool.h>
#include "type.h"

bool is_lista_players_vazia(no_t *ptr_lista_players);
void inicializa_lista(lista_t *lista_players);
no_t *novo_jogador();
void inserir_jogador(lista_t *lista, no_t *novo);

bool is_lista_jogos_vazia(no_jogos_t *ptr_lista_jogos);
void inicializa_lista_jogos(lista_jogos_t *lista_jogos);
no_jogos_t *novo_jogo(lista_t *lista_players);
void inserir_jogo(lista_jogos_t *lista_jogos, no_jogos_t *novo);


#endif