#include "../include/cadastro.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *condicoes[] = {"ATIVO", "LESIONADO", "VENDIDO"};

bool is_lista_players_vazia(no_t *ptr_lista_players)
{
    if (ptr_lista_players) return false;

    return true;
}

void inicializa_lista(lista_t *lista_players)
{
    lista_players->cabeca = NULL;
}

no_t *novo_jogador()
{
    no_t *novo;

    novo = (no_t*)malloc(sizeof(no_t));

    if (!novo) return NULL;

    printf("Nome do Jogador: ");
    fgets(novo->dados.nome, T_STR, stdin);
    retirar_enter(novo->dados.nome);
    to_upper(novo->dados.nome);

    printf("Idade: ");
    scanf("%d", &novo->dados.idade);

    printf("Altura: ");
    scanf("%f", &novo->dados.altura);

    printf("Peso: ");
    scanf("%f", &novo->dados.peso);

    printf("Posição do Jogador: ");
    getchar();
    fgets(novo->dados.posicao, T_STR, stdin);
    retirar_enter(novo->dados.posicao);
    to_upper(novo->dados.posicao);

    printf("Preço do Jogador: ");
    scanf("%f", &novo->dados.passe);

    printf("Valor de Aquisição: ");
    scanf("%f", &novo->dados.valor_aquis);

    printf("Salário: ");
    scanf("%f", &novo->dados.salario);

    int opc;
    int valido = 0;

    while (!valido) {
        printf("Jogador está:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d - %s\n", i, condicoes[i]);
        }
        printf("::: ");
        scanf("%d", &opc);
        getchar(); 

        if (opc >= 0 && opc < 3) {
            valido = 1;
            novo->dados.condicao = opc;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    novo->proximo = NULL;

    return novo;
}

void inserir_jogador(lista_t *lista, no_t *novo) {
    if (!novo) return;
    novo->proximo = lista->cabeca;
    lista->cabeca = novo;
}


//Partidas



bool is_lista_jogos_vazia(no_jogos_t *ptr_lista_jogos)
{
    if (ptr_lista_jogos) return false;

    return true;
}

void inicializa_lista_jogos(lista_jogos_t *lista_jogos)
{
        lista_jogos->cabeca_jogos = NULL;
}

no_jogos_t *novo_jogo(lista_t *lista_players)
{
    int total_escalados = 0;
    string nome_escolhido;
    no_jogos_t *nova_p;

    string nomes_ativos[MAX_JOGADORES];
    int qtde = 0;

    jogadores_ativos(lista_players->cabeca, nomes_ativos, &qtde);  

    nova_p = (no_jogos_t*)malloc(sizeof(no_jogos_t));
    if (!nova_p) return NULL;
 

    printf("Nome do time adversário: ");
    fgets(nova_p->dados_jogos.nome_time, T_STR, stdin);
    retirar_enter(nova_p->dados_jogos.nome_time);
    to_upper(nova_p->dados_jogos.nome_time);

    printf("Data do Jogo (dd/mm/aa): ");
    scanf("%d/%d/%d", &nova_p->dados_jogos.data.dia, &nova_p->dados_jogos.data.mes, &nova_p->dados_jogos.data.ano);
    getchar();

    printf("Local do Jogo: ");
    fgets(nova_p->dados_jogos.local, T_STR, stdin);
    retirar_enter(nova_p->dados_jogos.local);
    to_upper(nova_p->dados_jogos.local);

    printf("Resultado de Corinthians x %s\n", nova_p->dados_jogos.nome_time);
    printf("Corinthians: ");
    scanf("%d", &nova_p->dados_jogos.resultado_a);
    printf("%s: ", nova_p->dados_jogos.nome_time);
    scanf("%d", &nova_p->dados_jogos.resultado_b);
    getchar();

    msg_cabecalho("Escalação Corinthians:");

    while (total_escalados < MAX_JOGADORES) {
        printf("Jogador %d: ", total_escalados + 1);
        fgets(nome_escolhido, T_STR, stdin);
        retirar_enter(nome_escolhido);
        to_upper(nome_escolhido);

        if (nome_valido(nome_escolhido, nomes_ativos, qtde)) {
            strcpy(nova_p->dados_jogos.time_escalado[total_escalados], nome_escolhido);
            total_escalados++;
        } else {
            printf("Nome inválido ou jogador não está ATIVO. Tente novamente.\n");
        }
    }

    nova_p->proximo = NULL;
    return nova_p;
}

void inserir_jogo(lista_jogos_t *lista_jogos, no_jogos_t *novo_jogo)
{
    if (!novo_jogo) return;
    novo_jogo->proximo = lista_jogos->cabeca_jogos;
    lista_jogos->cabeca_jogos = novo_jogo;
}

