#ifndef ARQUIVOS_PARTIDAS_H
#define ARQUIVOS_PARTIDAS_H

#include "type.h"

void salvar_partidas_arquivo_binario(string nome_arq, no_jogos_t *ptr_lista_jogos);
void ler_partidas_arquivo_binario(string nome_arq, lista_jogos_t *lista_jogos);
void exportar_partidas_arquivo_texto(string nome_arq, no_jogos_t *lista_jogos);
void exportar_dados_partidas_arquivo_csv(string nome_arq, no_jogos_t *lista_jogos);


#endif