#include "../include/relatorios.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void relatorio_jogadores(no_t *ptr_lista_players)
{
    limpar_tela();

    msg_cabecalho("Jogadores Cadastrados");

    while(ptr_lista_players) {
        mostrar_jogadores(ptr_lista_players);
        ptr_lista_players = ptr_lista_players->proximo;
        printf("\n");
    }
    msg_press_enter();
}

void relatorio_por_idade(no_t *ptr_lista_players, int idade_min, int idade_max)
{
    limpar_tela();
    msg_cabecalho("Relatório por idade");

    int cont = 0;

    while (ptr_lista_players) {
        if(ptr_lista_players->dados.idade >= idade_min && ptr_lista_players->dados.idade <= idade_max) {
            mostrar_jogadores(ptr_lista_players);
            printf("\n");
            cont++;
        }

        ptr_lista_players = ptr_lista_players->proximo;
    }

    if (cont == 0) {
        printf("Nenhum jogador encontrado nesta faixa!");
    }

    msg_press_enter();

}

void relatorio_lesionados(no_t *ptr_lista_players)
{
    limpar_tela();
    msg_cabecalho("Relatorio Jogadores Lesionados");

    int cont = 0;

    while (ptr_lista_players) {
        if (ptr_lista_players->dados.condicao == 1) {
            mostrar_jogadores(ptr_lista_players);
            printf("\n");
            cont++;
        }

        ptr_lista_players = ptr_lista_players->proximo;
    }

    if (cont == 0) {
        printf("Nenhum jogador lesionado encontrado!");
    }

    msg_press_enter();

}

void relatorio_vendidos(no_t *ptr_lista_players)
{
    limpar_tela();
    msg_cabecalho("Relatorio de Vendas");

    no_t *aux = ptr_lista_players;
    float total_vendas = 0;
    int cont = 0;

    while (aux) {
        if (aux->dados.condicao == 2) {
            mostrar_jogadores(aux);
            printf("\n");
        }
        aux = aux->proximo;
    }

    while (ptr_lista_players) {
        if (ptr_lista_players->dados.condicao == 2) {
            total_vendas += ptr_lista_players->dados.passe;
            cont++;
        }
        ptr_lista_players = ptr_lista_players->proximo;
    }

    if (cont == 0) {
        printf("Nenhum jogador vendido!\n");
    }


    msg_press_enter();
}


void relatorio_vendas(no_t *ptr_lista_players)
{
    limpar_tela();
    msg_cabecalho("Relatorio de Vendas");

    no_t *aux = ptr_lista_players;
    float total_vendas = 0;
    int cont = 0;

    while (aux) {
        if (aux->dados.condicao == 2) {
            mostrar_jogadores(aux);
            printf("\n");
        }
        aux = aux->proximo;
    }

    while (ptr_lista_players) {
        if (ptr_lista_players->dados.condicao == 2) {
            total_vendas += ptr_lista_players->dados.passe;
            cont++;
        }
        ptr_lista_players = ptr_lista_players->proximo;
    }

    if (cont == 0) {
        printf("Nenhum jogador vendido!\n");
    } else {
        printf("A venda dos jogadores acima gerou o valor de: %.2f R$\n", total_vendas);
    }

    msg_press_enter();
}

void relatorio_salario(no_t *ptr_lista_players, float salario_min, float salario_max)
{
    limpar_tela();
    msg_cabecalho("Relatorio de Salário");

    int cont = 0;

    while(ptr_lista_players) {
        if (ptr_lista_players->dados.salario >= salario_min && ptr_lista_players->dados.salario <= salario_max) {
            mostrar_jogadores(ptr_lista_players);
            cont++;
        }

        ptr_lista_players = ptr_lista_players->proximo;
    }

    if (cont == 0) {
        printf("Nenhum jogador com salario deste intervalo\n");
    }

    msg_press_enter();
}


void mostrar_jogadores(no_t *jogador)
{
    printf("Jogador.................: %s\n", jogador->dados.nome);
    printf("Idade...................: %d\n", jogador->dados.idade);
    printf("Altura..................: %.2f\n", jogador->dados.altura);
    printf("Peso....................: %.2f\n", jogador->dados.peso);
    printf("Posição.................: %s\n", jogador->dados.posicao);
    printf("Valor de Mercado........: %.2f\n", jogador->dados.passe);
    printf("Valor de Aquisição......: %.2f\n", jogador->dados.valor_aquis);
    printf("Salário.................: %.2f\n", jogador->dados.salario);
    printf("Jogador.................: %d\n", jogador->dados.condicao);

}


//partidas


void relatorio_partidas(no_jogos_t *ptr_lista_jogos)
{
    limpar_tela();

    msg_cabecalho("Partidas Cadastradas");

    while(ptr_lista_jogos) {
        mostrar_partidas(ptr_lista_jogos);
        ptr_lista_jogos = ptr_lista_jogos->proximo;
        printf("\n");
    }

    msg_press_enter();
}

void relatorio_aproveitamento(desempenho_t indi)
{
    msg_cabecalho("Relatório de Aproveitamento");

    printf("Ganhou: %d\n", indi.partidas_ganhas);
    printf("Empatou: %d\n", indi.partidas_empatadas);
    printf("Perdeu: %d\n", indi.partidas_perdidas);
    printf("Gols feitos: %d\n", indi.gols_feitos);
    printf("Gols sofridos: %d\n", indi.gols_sofridos);
    printf("Saldo de gols: %d\n", indi.saldo_gols);
}


void mostrar_partidas(no_jogos_t *partida)
{
    printf("Time Adversário.........: %s\n", partida->dados_jogos.nome_time);
    printf("Data do Jogo............: %d/%d/%d\n", partida->dados_jogos.data.dia, partida->dados_jogos.data.mes, partida->dados_jogos.data.ano);
    printf("Local do Jogo...........: %s\n", partida->dados_jogos.local);
    printf("Resultado da Partida....: Corinthians %d x %d %s\n", partida->dados_jogos.resultado_a, partida->dados_jogos.resultado_b, partida->dados_jogos.nome_time);
    printf("Time Escalado...........:\n");
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("Jogador %d: .............: %s\n", i + 1, partida->dados_jogos.time_escalado[i]);

    }
}
