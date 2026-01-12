#ifndef ARQUIVOS_JOGADORES_H
#define ARQUIVOS_JOGADORES_H

#include "type.h"

void salvar_jogadores_arquivo_binario(string nome_arq, no_t *ptr_lista_players);
void ler_jogadores_arquivo_binario(string nome_arq, lista_t *lista_players);
void exportar_jogador_arquivo_texto(string nome_arq, no_t *lista_players);
void exportar_dados_jogadores_arquivo_csv(string nome_arq, no_t *lista_players);


#endif