#include "../include/buscas.h"
#include "../include/relatorios.h"

#include <string.h>
#include <stdbool.h>



no_t *buscar_jogador(string nome, no_t *lista)
{
    while (lista) {
        if (strcmp(nome, lista->dados.nome)== 0) {
            return lista;
        }

        lista = lista->proximo;
    }

    return NULL;
}

void buscar_posicao(string posicao, no_t *lista) 
{
    bool flag = false;
    
    while (lista) {
        if (strcmp(posicao, lista->dados.posicao)== 0) {
            mostrar_jogadores(lista);
            printf("\n");

            flag = true;
        }

        lista = lista->proximo;
    }

    if (!flag) {
        printf("Não ha jogadores na posição %s cadastrados!", posicao);
    }

    msg_press_enter();
}

void buscar_maior_salario(no_t *lista)
{
    if (!lista) {
        printf("Lista vazia!");
        return;
    }
    
    no_t *maior = lista;
    
    while(lista != NULL) {
        if (lista->dados.salario > maior->dados.salario) {
            maior = lista;

        }
        lista = lista->proximo;
    }

    mostrar_jogadores(maior);
}

//Partidas


void buscar_partidas_adversario(string nome_adversario, no_jogos_t *lista)
{
    int encontrou = 0;
    while (lista) {
        if (strcmp(nome_adversario, lista->dados_jogos.nome_time) == 0) {
            mostrar_partidas(lista);
            encontrou = 1;
        }
        lista = lista->proximo;
    }

    if (!encontrou) {
        printf("Nenhuma partida contra o adversário \"%s\" foi encontrada.\n", nome_adversario);
    }

    msg_press_enter();
}

