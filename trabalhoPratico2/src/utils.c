#include "../include/utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void retirar_enter(string str)
{
    *(str+strlen(str)-1) = '\0';
}

void to_upper(string str) 
{
    for (size_t i = 0; i < strlen(str); i++) {
        *(str+i) = toupper(*(str+i));
    }
}

void limpar_tela()
{
    system("clear");
}

void msg_press_enter()
{
    printf("\n-----------------------------------------------\n");
    printf("Pressione ENTER para retornar ao MENU RELATORIOS\n");
    getchar();
}

void msg_cabecalho(string msg)
{
    printf("==============================================\n");
    printf("%s\n", msg);
    printf("==============================================\n\n");
}

void jogadores_ativos(no_t *lista, string nomes_ativos[], int *qtde)
{
    *qtde = 0;  

    while (lista != NULL) {
        if (lista->dados.condicao == 0) {
            strcpy(nomes_ativos[*qtde], lista->dados.nome);
            (*qtde)++;
        }
        lista = lista->proximo; 
    }
}

bool nome_valido(string nome, string lista_nomes[], int qtde) {
    for (int i = 0; i < qtde; i++) {
        if (strcmp(nome, lista_nomes[i]) == 0) {
            return true;
        }
    }
    return false;
}



desempenho_t aproveitamento(no_jogos_t *ptr_lista_jogos)
{
    desempenho_t indi = {0};

    while (ptr_lista_jogos) {
        int gols_cor = ptr_lista_jogos->dados_jogos.resultado_a;
        int gols_adv = ptr_lista_jogos->dados_jogos.resultado_b;

        if (gols_cor > gols_adv) {
            indi.partidas_ganhas++;
        } else if (gols_cor < gols_adv) {
            indi.partidas_perdidas++;
        } else {
            indi.partidas_empatadas++;
        }

        indi.gols_feitos += gols_cor;
        indi.gols_sofridos += gols_adv;
        indi.saldo_gols += (gols_cor - gols_adv);

        ptr_lista_jogos = ptr_lista_jogos->proximo;
    }

    return indi;
}
