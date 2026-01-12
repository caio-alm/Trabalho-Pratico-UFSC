#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "type.h"
#include "utils.h"

void relatorio_jogadores(no_t *ptr_lista_players);
void relatorio_por_idade(no_t *ptr_lista_players, int idade_min, int idade_max);
void relatorio_lesionados(no_t *ptr_lista_players);
void relatorio_vendidos(no_t *ptr_lista_players);
void relatorio_vendas(no_t *ptr_lista_players);
void relatorio_salario(no_t *ptr_lista_players, float salario_max, float salario_min);
void mostrar_jogadores(no_t *jogador);

void relatorio_partidas(no_jogos_t *ptr_lista_jogos);
void relatorio_aproveitamento(desempenho_t indi);
void mostrar_partidas(no_jogos_t *partida);


#endif