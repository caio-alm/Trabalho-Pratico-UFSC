#ifndef TYPE_H
#define TYPE_H

#define T_STR 100
#define MAX_JOGADORES 11

typedef char string[T_STR];

typedef struct data {
    int dia;
    int mes;
    int ano;
} data_t;


typedef struct desempenho {
    int partidas_ganhas;
    int partidas_perdidas;
    int partidas_empatadas;
    int gols_feitos;
    int gols_sofridos;
    int saldo_gols;
} desempenho_t;

typedef struct dados_jogadores {
    string nome;
    int idade;
    float altura;
    float peso;
    string posicao;
    float passe;
    float valor_aquis;
    float salario;
    int condicao;
} dados_jogadores_t;

typedef struct jogos {
    string nome_time;
    data_t data;
    string local;
    int resultado_a;
    int resultado_b;
    string time_escalado[MAX_JOGADORES];
    int substituicao;

} jogos_t;

typedef struct no {
    dados_jogadores_t dados;
    struct no *proximo;
} no_t;

typedef struct no_jogos {
    jogos_t dados_jogos;
    struct no_jogos *proximo;
} no_jogos_t;

typedef struct lista {
    no_t *cabeca;
} lista_t;

typedef struct lista_jogos {
    no_jogos_t *cabeca_jogos;
}lista_jogos_t;

#endif