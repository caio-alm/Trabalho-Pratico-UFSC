#include "../include/arquivos_jogadores.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/cadastro.h"

void salvar_jogadores_arquivo_binario(string nome_arq, no_t *ptr_lista_players)
{
    FILE *fp;

    fp = fopen(nome_arq, "wb");

    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    while (ptr_lista_players) {
        fwrite(ptr_lista_players, sizeof(no_t), 1, fp);
        ptr_lista_players = ptr_lista_players->proximo;
    }

    fclose(fp);
}


void ler_jogadores_arquivo_binario(string nome_arq, lista_t *lista_players)
{
    FILE *fp;

    fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }

    while(!feof(fp)) {
        no_t *aux = (no_t*)malloc(sizeof(no_t));
        fread(aux, sizeof(no_t), 1, fp);
        if (!feof(fp)) { 
            aux->proximo = NULL;
            inserir_jogador(lista_players, aux);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

void exportar_jogador_arquivo_texto(string nome_arq, no_t *lista_players)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "----------------------------------\n");
    fprintf(fp, "Relatorio Completo de jogadores\n");
    fprintf(fp, "----------------------------------\n\n");

    while(lista_players) {
        fprintf(fp, "Jogador.................: %s\n", lista_players->dados.nome);
        fprintf(fp, "Idade...................: %d\n", lista_players->dados.idade);
        fprintf(fp, "Altura..................: %.2f\n", lista_players->dados.altura);
        fprintf(fp, "Peso....................: %.2f\n", lista_players->dados.peso);
        fprintf(fp, "Posição.................: %s\n", lista_players->dados.posicao);
        fprintf(fp, "Valor de Mercado........: %.2f\n", lista_players->dados.passe);
        fprintf(fp, "Valor de Aquisição......: %.2f\n", lista_players->dados.valor_aquis);
        fprintf(fp, "Salário.................: %.2f\n", lista_players->dados.salario);
        fprintf(fp, "Jogador.................: %d\n", lista_players->dados.condicao);
        fprintf(fp, "\n");
        lista_players = lista_players->proximo;
    }      

    fclose(fp); 
}


void exportar_dados_jogadores_arquivo_csv(string nome_arq, no_t *lista_players)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "NOME;Idade;Altura;Peso;Posição;Passe;Preço Pago;Salário;Condição\n");

    while(lista_players) {
        fprintf(fp, "%s;", lista_players->dados.nome);
        fprintf(fp, "%d;", lista_players->dados.idade);
        fprintf(fp, "%.2f;", lista_players->dados.altura);
        fprintf(fp, "%.2f;", lista_players->dados.peso);
        fprintf(fp, "%s;", lista_players->dados.posicao);
        fprintf(fp, "%.2f;", lista_players->dados.passe);
        fprintf(fp, "%.2f;", lista_players->dados.valor_aquis);
        fprintf(fp, "%.2f;", lista_players->dados.salario);
        fprintf(fp, "%d\n", lista_players->dados.condicao);
        
        lista_players = lista_players->proximo;
    }    

    fclose(fp); 

}