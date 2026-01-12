#include "../include/arquivos_partidas.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/cadastro.h"

void salvar_partidas_arquivo_binario(string nome_arq, no_jogos_t *ptr_lista_jogos)
{
    FILE *fp;

    fp = fopen(nome_arq, "wb");

    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    while (ptr_lista_jogos) {
        fwrite(ptr_lista_jogos, sizeof(no_jogos_t), 1, fp);
        ptr_lista_jogos = ptr_lista_jogos->proximo;
    }

    fclose(fp);
}


void ler_partidas_arquivo_binario(string nome_arq, lista_jogos_t *lista_jogos)
{
    FILE *fp;

    fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }

    while(!feof(fp)) {
        no_jogos_t *aux = (no_jogos_t*)malloc(sizeof(no_jogos_t));
        fread(aux, sizeof(no_jogos_t), 1, fp);
        if (!feof(fp)) { 
            aux->proximo = NULL;
            inserir_jogo(lista_jogos, aux);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

void exportar_partidas_arquivo_texto(string nome_arq, no_jogos_t *lista_jogos)
{
        FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "----------------------------------\n");
    fprintf(fp, "Relatorio Completo de Partidas\n");
    fprintf(fp, "----------------------------------\n\n");

    while(lista_jogos) {
        fprintf(fp, "Time Adversário.........: %s\n", lista_jogos->dados_jogos.nome_time);
        fprintf(fp, "Data do Jogo............: %d/%d/%d\n", lista_jogos->dados_jogos.data.dia, lista_jogos->dados_jogos.data.mes, lista_jogos->dados_jogos.data.ano);
        fprintf(fp, "Local do Jogo...........: %s\n", lista_jogos->dados_jogos.local);
        fprintf(fp, "Resultado da Partida....: Corinthians %d x %d %s\n", lista_jogos->dados_jogos.resultado_a, lista_jogos->dados_jogos.resultado_b, lista_jogos->dados_jogos.nome_time);
        fprintf(fp, "Time Escalado...........:\n ");
        for (int i = 0; i < MAX_JOGADORES; i++){
            fprintf(fp, "Jogador %d: .............: %s\n ", i + 1, lista_jogos->dados_jogos.time_escalado[i]);
        }
        fprintf(fp, "\n");
        lista_jogos = lista_jogos->proximo;
    }      

    fclose(fp); 

}

void exportar_dados_partidas_arquivo_csv(string nome_arq, no_jogos_t *lista_jogos)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "Time Adversário;Data do Jogo;Local;Resultado da Partida;Time Escalado\n");

    while(lista_jogos) {
        fprintf(fp, "%s;", lista_jogos->dados_jogos.nome_time);
        fprintf(fp, "%d/%d/%d;", lista_jogos->dados_jogos.data.dia, lista_jogos->dados_jogos.data.mes, lista_jogos->dados_jogos.data.ano);
        fprintf(fp, "%s;", lista_jogos->dados_jogos.local);
        fprintf(fp, "Corinthians %d x %d %s;", lista_jogos->dados_jogos.resultado_a, lista_jogos->dados_jogos.resultado_b, lista_jogos->dados_jogos.nome_time);
        for (int i = 0; i < MAX_JOGADORES; i++){
            fprintf(fp, "%s|", lista_jogos->dados_jogos.time_escalado[i]);
        }
        fprintf(fp, "\n");
        lista_jogos = lista_jogos->proximo;
    }    

    fclose(fp); 

}

