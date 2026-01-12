#ifndef BUSCAS_H
#define BUSCAS_H

#include "type.h"

no_t *buscar_jogador(string nome, no_t *lista);
void buscar_posicao(string posicao, no_t *lista);
void buscar_maior_salario(no_t *lista);


void buscar_partidas_adversario(string nome_adversario, no_jogos_t *lista);


#endif