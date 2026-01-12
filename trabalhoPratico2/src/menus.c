#include <stdio.h>
#include <stdint.h>
#include "../include/menus.h"
#include "../include/utils.h"

uint8_t menu_principal()
{
    uint8_t opcao;

    limpar_tela();

    printf("================MENU PRINCIPAL================\n");
    printf("\t1-Cadastros\n");
    printf("\t2-Relatorios\n");
    printf("\t3-Buscas\n");
    printf("\t4-Arquivos\n");
    printf("----------------------------------------------\n");
    printf("\t0-Sair do programa\n");
    printf("==============================================\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();
    
    return opcao;
}   

uint8_t menu_cadastros()
{
    uint8_t opcao;

    limpar_tela();

    printf("================MENU CADASTROS================\n");
    printf("\t1-Cadastrar Jogador\n");
    printf("\t2-Cadastrar Partida\n");
    printf("----------------------------------------------\n");
    printf("\t0-Retornar ao menu principal\n");
    printf("==============================================\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}

uint8_t menu_relatorios()
{
    uint8_t opcao;

    limpar_tela();

    printf("================MENU RELATÓRIOS===============\n");
    printf("-------------------JOGADORES------------------\n");
    printf("\t1-Relatório Jogadores\n");
    printf("\t2-Relatório por Idade\n");
    printf("\t3-Relatório Jogadores Lesionados\n");
    printf("\t4-Relatório Jogadores Vendidos\n");
    printf("\t5-Relatório de Vendas\n");
    printf("\t6-Relatório por Salário\n");
    printf("-------------------PARTIDAS-------------------\n");
    printf("\t7-Relatório de Partidas\n");
    printf("\t8-Relatório de Aproveitamento\n");
    printf("\t9-Relatório de Partidas por Adversário\n");
    printf("----------------------------------------------\n");
    printf("\t0-Retornar ao menu principal\n");
    printf("==============================================\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;

}

uint8_t menu_buscas()
{
    uint8_t opcao;

    limpar_tela();

    printf("==================MENU BUSCAS=================\n");
    printf("-------------------JOGADORES------------------\n");
    printf("\t1-Buscar Jogador\n");
    printf("\t2-Buscar por Posição\n");
    printf("\t3-Buscar Jogador Maior Salário\n");
    printf("-------------------PARTIDAS-------------------\n");
    printf("\t4-Buscar por Time Adversário\n");
    printf("----------------------------------------------\n");
    printf("\t0-Retornar ao menu principal\n");
    printf("==============================================\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;

}

uint8_t menu_arquivos()
{
     uint8_t opcao;

    limpar_tela();

    printf("=================MENU ARQUIVOS================\n");
    printf("-------------------JOGADORES------------------\n");
    printf("1-Exportar jogadores para aquivo texto\n");
    printf("2-Exportar jogadores para formato csv (Excel)\n");
    printf("-------------------PARTIDAS-------------------\n");
    printf("3-Exportar partidas para aquivo texto\n");
    printf("4-Exportar partidas para formato csv (Excel)\n");
    printf("----------------------------------------------\n");
    printf("0-Retornar ao menu principal\n");
    printf("==============================================\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}
