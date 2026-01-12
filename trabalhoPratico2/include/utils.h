#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdbool.h>
#include "type.h"

void retirar_enter(string str);
void to_upper(string str);
void limpar_tela();
void msg_press_enter();
void msg_cabecalho(string msg);
void jogadores_ativos(no_t *lista, string nomes_ativos[], int *qtd_ativos);
bool nome_valido(string nome, string lista_nomes[], int qtde);
desempenho_t aproveitamento(no_jogos_t *ptr_lista_jogos);


#endif