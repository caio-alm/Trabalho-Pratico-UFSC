#include <stdio.h>
#include <string.h>
#include <strings.h>//Utilizando o strcasecmp ele ignora as letras maiusculas e minusculas
#include <ctype.h> //Utilizado no cadastro do jogadores a função tolower()
#include <stdlib.h> //Utilizando função system para limpar o terminal   

#define TAM 100
typedef char players[50][TAM];
typedef char string[TAM];

typedef struct dados_jogadores {
    string nome;
    int idade;
    float altura;
    float peso;
    string posicao;
    float passe;
    float valor_aquis;
    float salario;
    string condicao;
} dados_jogadores_t;

typedef struct jogos {
    string nome_time;
    string data;
    string local;
    int resultado_a;
    int resultado_b;
    players time_escalado;
    int substituicao;

} jogos_t;

typedef struct base_dados {
    dados_jogadores_t jogadores[TAM];
    jogos_t parti[TAM];
    int qtd_jogadores;
    int qtd_partidas;
} base_dados_t;

base_dados_t dados;
dados_jogadores_t cadastro(void);
jogos_t cadastro_jogos(void);

int menu(void);

//Complementares
void mostrar_partidas(int i);
void mostrar_jogadores(int i);
int validar_qtd_jogadores(void);
int validar_qtd_partidas(void);
int condicao(void);
void limpar_terminal(void);
void pausa(void);

//Relatórios
void relatorio_jogadores(void);
void filtro_idade(void);
void relatorio_partidas(void);
void relatorio_partida_user(void);
int jogadores_vendidos(void);
int jogadores_lesionados(void);
void valor_vendas(void);
void aproveitamento(void);

//Buscas
void busca_jogador(void);
void busca_jogador_pos(void);
void busca_time_adversario(void);
void jogador_maior_salario(void);
void filtro_salario(void);

//Utilizada para melhor funcionamento da função condicao()
const char lesao[] = "Jogador Lesionado";
const char vendido[] = "Jogador Vendido";
const char ativo[] = "Jogador em Atividade";

int main()
{
    int opcao;


    //Optei fazer um menu limpo, então utilizei funções sem parâmetros
    do {
        limpar_terminal();
        opcao = menu();

        switch (opcao) {
            case 1: cadastro();
                    break;

            case 2: cadastro_jogos();
                    break;

            case 3: relatorio_jogadores();
                    break;

            case 4: busca_jogador();
                    break;

            case 5: busca_jogador_pos();
                    break;

            case 6: filtro_idade();
                    break;

            case 7: jogador_maior_salario();
                    break;

            case 8: filtro_salario();
                    break;

            case 9: jogadores_vendidos();
                    break;

            case 10: jogadores_lesionados();
                    break;

            case 11: relatorio_partidas();
                    break;

            case 12: relatorio_partida_user();
                    break;

            case 13: valor_vendas();
                    break;

            case 14: aproveitamento();
                    break;

            case 15: busca_time_adversario();
                    break;
        }

        if (opcao != 0) {
            pausa();
        }

    } while (opcao != 0);

    
    return 0;
}

//Cadastros:

//Cadastro de jogadores
dados_jogadores_t cadastro(void)
{
    dados_jogadores_t jogador;
    

    
    getchar();
    printf("Nome do jogador:\n::");
    fgets(jogador.nome, TAM, stdin);
    printf("Idade do jogador\n::");
    scanf("%d", &jogador.idade);
    getchar();
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';
    printf("Altura do jogador:\n::");
    scanf("%f", &jogador.altura);
    getchar();
    printf("Peso do Jogador;\n::");
    scanf("%f", &jogador.peso);
    getchar();
    printf("Posição do jogador:\n::");
    fgets(jogador.posicao, TAM, stdin);
    jogador.posicao[strcspn(jogador.posicao, "\n")] = '\0';
    printf("Preço do jogador atualmentente:\n::");
    scanf("%f", &jogador.passe);
    getchar();
    printf("Valor de aquisição:\n::");
    scanf("%f", &jogador.valor_aquis);
    getchar();
    printf("Salário:\n::");
    scanf("%f", &jogador.salario);
    getchar();
    printf("Jogador em atividade?(Sim/Não)\n::");
    fgets(jogador.condicao, TAM, stdin);
    int valido = 0;

    
    do {
        
        jogador.condicao[strcspn(jogador.condicao, "\n")] = '\0';
    
        //jogador.condicao passa a ser minusculo para melhor filtragem do programa
        for (int i = 0; jogador.condicao[i] != '\0'; i++) {
            jogador.condicao[i] = tolower(jogador.condicao[i]);
        }

        //Para melhor entendimento do usuario ao longo do programa
        if (strcmp(jogador.condicao, "não") == 0 || strcmp(jogador.condicao, "sim") == 0) {
            if (strcmp(jogador.condicao, "não") == 0) {
                valido = 1;
                int status = condicao();
                if (status == 1) {
                    strcpy(jogador.condicao, lesao);
                }
                else {
                    strcpy(jogador.condicao, vendido);
                }
            }
        }

            if (strcmp(jogador.condicao, "sim") == 0) {
                strcpy(jogador.condicao, ativo);
                valido = 1;
            }
    
    } while (valido != 1);

    

    dados.jogadores[dados.qtd_jogadores] = jogador;
    dados.qtd_jogadores++;

    return jogador;
}

jogos_t cadastro_jogos(void)
{
    jogos_t partidas;
    
    //Cadastro de Jogos
    getchar();
    printf("Nome do time adversário:\n::");
    fgets(partidas.nome_time, TAM, stdin);
    partidas.nome_time[strcspn(partidas.nome_time, "\n")] = '\0';
    printf("Quando o jogo vai ser realizado:\n::");
    fgets(partidas.data, TAM, stdin);
    partidas.data[strcspn(partidas.data, "\n")] = '\0';
    printf("Local onde o jogo vai ser realizado:\n::");
    fgets(partidas.local, TAM, stdin);
    partidas.local[strcspn(partidas.local, "\n")] = '\0';
    printf("Resultado da partida Corinthians x %s\n", partidas.nome_time);
    printf("Corinthians: ");
    scanf("%d", &partidas.resultado_a);
    printf("%s:", partidas.nome_time);
    scanf("%d", &partidas.resultado_b);
    getchar();

    for (int i = 0; i < 11; i++) {
        printf("Nome jogador %d:", i + 1);
        fgets(partidas.time_escalado[i], TAM, stdin);
        partidas.time_escalado[i][strcspn(partidas.time_escalado[i], "\n")] = '\0';
        
    }

    int subs;
    printf("Quantas substituições foram feitas?\n::");
    scanf("%d", &subs);

    if (subs >= 0 && subs <= 5) {
        partidas.substituicao = subs;
    }


    dados.parti[dados.qtd_partidas] = partidas;
    dados.qtd_partidas++;

    return partidas;

}

//Menu
int menu(void)
{
    int opc;
    
    printf("======================MENU===================\n");
    printf("1-Cadastrar jogador\n");
    printf("2-Registrar partida\n");
    printf("-------------------JOGADORES-----------------\n");
    printf("3-Relatorio Jogadores\n");
    printf("4-Buscar Jogador\n");
    printf("5-Buscar Jogador por posição\n");
    printf("6-Filtrar por idade\n");
    printf("7-Jogador com Maior Salário\n");
    printf("8-Filtrar por Salário\n");
    printf("9-Jogadores Vendidos\n");
    printf("10-Jogadores Lesionados\n");
    printf("-------------------PARTIDAS------------------\n");
    printf("11-Relatório de Partidas\n");
    printf("12-Relatório Partidas por Adversário\n");
    printf("13-Valor Recebido Por Vendas\n");
    printf("14-Aproveitamento do Time\n");
    printf("15-Buscar partidas pelo time adversario\n");
    printf("=============================================\n");
    printf("0-Sair do programa\n");
    printf("=============================================\n");
    printf("Opção:");
    scanf("%d", &opc);
    printf("=============================================\n");

    return opc;
}

//Funções Complementares:

//Mesma ideia do mostrar_jogadores(), utilizei para deixar mais limpo
void mostrar_partidas(int i)
{
    printf("Time Adversário: %s\n", dados.parti[i].nome_time);
    printf("Data do Confronto: %s\n", dados.parti[i].data);
    printf("Local: %s\n", dados.parti[i].local);
    printf("Corinthians %d x %s %d\n", dados.parti[i].resultado_a, dados.parti[i].nome_time, dados.parti[i].resultado_b);
    printf("Time Escalado Corinthians:\n");
    printf("=============================================\n");
    for (int j = 0; j < 11; j++) {
        printf("%s\n", dados.parti[i].time_escalado[j]);
    }
    printf("=============================================\n");
    printf("%d Substituições\n", dados.parti[i].substituicao);
    printf("=============================================\n");

}

//Para ser um codigo mais limpo
void mostrar_jogadores(int i)
{
    printf("=============================================\n");
    printf("Jogador: %s\n", dados.jogadores[i].nome);
    printf("Idade: %d\n", dados.jogadores[i].idade);
    printf("Altura: %.2f\n", dados.jogadores[i].altura);
    printf("Peso: %.2f\n", dados.jogadores[i].peso);
    printf("Posição: %s\n", dados.jogadores[i].posicao);
    printf("Passe: %.2f\n", dados.jogadores[i].passe);
    printf("Valor pago: %.2f\n", dados.jogadores[i].valor_aquis);
    printf("Salário: %.2f\n", dados.jogadores[i].salario);
    printf("Condição: %s\n", dados.jogadores[i].condicao);
    printf("=============================================\n");

}

//Utilizo para ver se já tem algum jogador cadastrado
int validar_qtd_jogadores(void)
{
    if (dados.qtd_jogadores > 0){
        return 1;
    }
    else {
        printf("Nenhum jogador cadastrado!\n");
        printf("=============================================\n");
        return 0;
    }
}

//Utilizo para ver se já tem alguma partida cadastrada
int validar_qtd_partidas(void)
{
    if (dados.qtd_partidas > 0){
        return 1;
    }
    else {
        printf("Nenhuma partida cadastrada!\n");
        printf("=============================================\n");
        return 0;
    }
}

//Utilizada no cadastro do jogador
int condicao(void)
{
    int opc;

    
    printf("Motivo:\n");
    printf("=============================================\n");
    printf("1-Jogador Vendido.\n");
    printf("2-Jogador Lesionado.\n");
    printf("=============================================\n");
    printf("::");
    scanf("%d", &opc);

    switch (opc) {
        case 1: return 0;

        case 2: return 1;
    }
}

//Faz o usuario digitar enter para voltar ao menu
//melhorando a legibilidade dos resultados
void pausa(void)
{
    printf("Aperte ENTER para voltar ao menu:");
    getchar();
    getchar();
}

//Limpa o terminal deixando mais limpo
void limpar_terminal(void)
{
    system("clear");
}

//Relatórios:

void relatorio_jogadores(void)
{
    if (validar_qtd_jogadores() == 0) {
        return;

    }

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        printf("Jogador: %s\n", dados.jogadores[i].nome);
        printf("Idade: %d\n", dados.jogadores[i].idade);
        printf("Altura: %.2f\n", dados.jogadores[i].altura);
        printf("Peso: %.2f\n", dados.jogadores[i].peso);
        printf("Posição: %s\n", dados.jogadores[i].posicao);
        printf("Passe: %.2f\n", dados.jogadores[i].passe);
        printf("Valor pago: %.2f\n", dados.jogadores[i].valor_aquis);
        printf("Salário: %.2f\n", dados.jogadores[i].salario);
        printf("Condição: %s\n", dados.jogadores[i].condicao);
    printf("=============================================\n");
    }
}


//Procura o jogador entre as idades escolhidas pelo user
void filtro_idade(void)
{
    if (validar_qtd_jogadores() == 0) {
        return;
    }
    
    int idade_user;
    int idade_userm;
    //Utilizei o "cont" durante o codigo para validar
    //se certas condições são verdadeiras e mostrar ao usuario
    int cont = 0;

    printf("Digite o filtro de idade:\n");
    printf("Filtro 1:");
    scanf("%d", &idade_user);
    printf("Filtro 2:");
    scanf("%d", &idade_userm);

    for(int i = 0; i < dados.qtd_jogadores; i++) {
        if (dados.jogadores[i].idade > idade_user && dados.jogadores[i].idade < idade_userm) {
            //Ao invés de passar os endereços das variaveis varias vezes só chamo a função
            mostrar_jogadores(i);
            cont = 1;
        }
    }
    if (cont == 0){
        printf("=============================================\n");
        printf("Nenhum Jogador encontrado nesta faixa de idade.\n");
        printf("=============================================\n");
    }
}

void relatorio_partidas(void)
{
    if (validar_qtd_partidas() == 0) {
        return;
    }

    int partidas_ganhas = 0;
    int partidas_emp = 0;
    int partidas_per = 0;
    int gols = 0;
    int gols_adversarios = 0;
    int saldo_gols = 0;

    //Mostra ao usuário todas as partidas cadastradas
    for (int i = 0; i < dados.qtd_partidas; i++) {
        mostrar_partidas(i);
        if (dados.parti[i].resultado_a > dados.parti[i].resultado_b) {
                partidas_ganhas++;
            }
            if (dados.parti[i].resultado_a == dados.parti[i].resultado_b) {
                partidas_emp++;
            }
            if (dados.parti[i].resultado_a < dados.parti[i].resultado_b) {
                partidas_per++;
            }

            gols += dados.parti[i].resultado_a;
            gols_adversarios += dados.parti[i].resultado_b;
            saldo_gols = gols - gols_adversarios;

    }  
    printf("Relatórios de todas as partidas, o Corinthians:\n");
    printf("=============================================\n");
    printf("Ganhou: %d\n", partidas_ganhas);
    printf("Empatou: %d\n", partidas_emp);
    printf("Perdeu: %d\n", partidas_per);
    printf("Gols feitos: %d\n", gols);
    printf("Gols sofridos: %d\n", gols_adversarios);
    printf("Saldo de gols: %d\n", saldo_gols);
    printf("=============================================\n");
}



//Mostra ao usuario as partidas contra o time determinado pelo mesmo
void relatorio_partida_user(void)
{
    if (validar_qtd_partidas() == 0) {
        return;
    }

    string time_ad;
    int partidas_ganhas = 0;
    int partidas_emp = 0;
    int partidas_per = 0;
    int gols = 0;
    int gols_adversarios = 0;
    int saldo_gols = 0;
    float taxa_aprov;
    int cont = 0;

    getchar();
    printf("Digite o time desejado:" );
    fgets(time_ad, TAM, stdin);
    time_ad[strcspn(time_ad, "\n")] = '\0';
    for (int i = 0; i < dados.qtd_partidas; i++) {
        //strcmp retorna 0 se o if for verdadeiro por isso o == 0
        if (strcasecmp(time_ad, dados.parti[i].nome_time) == 0) {
            mostrar_partidas(i);
            cont++;
            if (dados.parti[i].resultado_a > dados.parti[i].resultado_b) {
                partidas_ganhas++;
            }
            if (dados.parti[i].resultado_a == dados.parti[i].resultado_b) {
                partidas_emp++;
            }
            if (dados.parti[i].resultado_a < dados.parti[i].resultado_b) {
                partidas_per++;
            }
            gols += dados.parti[i].resultado_a;
            gols_adversarios += dados.parti[i].resultado_b;
            saldo_gols = gols - gols_adversarios;
        }
        
        }

    if (cont != 0) {
        printf("Contra o  %s, o Corinthians:\n", time_ad);
        printf("=============================================\n");
        printf("Ganhou: %d\n", partidas_ganhas);
        printf("Empatou: %d\n", partidas_emp);
        printf("Perdeu: %d\n", partidas_per);
        printf("Gols feitos: %d\n", gols);
        printf("Gols sofridos: %d\n", gols_adversarios);
        printf("Saldo de gols: %d\n", saldo_gols);

        printf("=============================================\n");
    }

    if (cont == 0) {
            printf("Nenhuma partida encontrada\n");
            printf("=============================================\n");    
    }
}

int jogadores_vendidos(void)
{
    if (validar_qtd_jogadores() == 0) {
        return 0;
    }

    int cont = 0;

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        if(strcmp(dados.jogadores[i].condicao, vendido) == 0) {
            cont = 1;
        }
    }
    
    if (cont == 1) {
        printf("Jogadores Vendidos\n");
    }  

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        if(strcmp(dados.jogadores[i].condicao, vendido) == 0) {
            mostrar_jogadores(i);
        }
    }
    if (cont == 0) {
        printf("Nenhum Jogador Vendido.\n");
        printf("=============================================\n");
    }

    return cont;
}

int jogadores_lesionados(void) 
{
    if (validar_qtd_jogadores() == 0) {
        return 0;
    }

    int cont = 0;

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        if(strcmp(dados.jogadores[i].condicao, lesao) == 0) {
            cont = 1;
        }
    }
    
    if (cont == 1) {
        printf("Jogadores Lesionados\n");
    }  

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        if(strcmp(dados.jogadores[i].condicao, lesao) == 0) {
            mostrar_jogadores(i);
        }
    }
    if (cont == 0) {
        printf("Nenhum Jogador lesionado.\n");
        printf("=============================================\n");
    }

    return cont;
}

void valor_vendas(void) 
{
    if (validar_qtd_jogadores() == 0) {
        return;
    }

    if (jogadores_vendidos() == 0){
        return;
    }

    float total_vendas = 0;

    printf("=============================================\n");
    printf("Jogadores Vendidos\n");
    printf("=============================================\n");
    jogadores_vendidos();

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        //strcasecmp ele ignora as letras maiusculas e minusculas
        if (strcasecmp(dados.jogadores[i].condicao, vendido) == 0) {
            total_vendas += dados.jogadores[i].passe;
        }
    }

    printf("=============================================\n");
    printf("A venda dos jogadores acima geraram o valor de: ");
    printf("%2.fR$\n", total_vendas);
    printf("=============================================\n");
}

void aproveitamento(void)
{
    if (validar_qtd_partidas() == 0) {
        return;
    }
    
    int partidas_ganhas = 0;
    int partidas_emp = 0;
    int partidas_per = 0;
    float taxa_aprov;
    int cont = 0;

    for (int i = 0; i < dados.qtd_partidas; i++) {
        if (dados.parti[i].resultado_a > dados.parti[i].resultado_b) {
            partidas_ganhas++;
            cont = 1;
        }
        if (dados.parti[i].resultado_a == dados.parti[i].resultado_b) {
            partidas_emp++;
            cont = 1;
        }
        if (dados.parti[i].resultado_a < dados.parti[i].resultado_b) {
            partidas_per++;
            cont = 1;
        }

    }

    //(float) faz o resultado da expressão ser do tipo float o que melhor se enquadra
    if (cont == 1) {    
        taxa_aprov = (float)partidas_ganhas / dados.qtd_partidas * 100;
        printf("Estatística Geral\n");
        printf("=============================================\n");
        printf("Partidas Ganhas: %d\n", partidas_ganhas);
        printf("Partidas Empatadas: %d\n", partidas_emp);
        printf("Partidas Perdidas: %d\n", partidas_per);
        printf("O aproveitamento do time é de: %2.f\n", taxa_aprov);
        printf("=============================================\n");
    }    
}

//Buscas:

//Busca o jogador escolhido pelo usuario
void busca_jogador(void)
{
    if (validar_qtd_jogadores() == 0) {
        return;
    }

    string nome_user;
    int cont = 0;

    getchar();
    printf("Digite o nome do jogador desejado:\n");
    printf("::");
    fgets(nome_user, TAM, stdin);
    nome_user[strcspn(nome_user, "\n")] = '\0';

    
    for (int i = 0; i < dados.qtd_jogadores; i++) {
        if (strcasecmp(nome_user, dados.jogadores[i].nome) == 0) {
            mostrar_jogadores(i);
            cont = 1;
        }
    }

    if (cont == 0) {
        printf("=============================================\n");
        printf("Nenhum Jogador Encontrado.\n");
        printf("=============================================\n");
    }
}

//Busca os jogadores por posição e mostra eles
void busca_jogador_pos(void)
{
    if (validar_qtd_jogadores() == 0) {
        return;
    }
    
    string posicao;    
    int cont = 0;

    getchar();
    printf("Digite a posição desejada:\n");
    printf("::");
    fgets(posicao, TAM, stdin);
    posicao[strcspn(posicao, "\n")] = '\0';

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        if (strcasecmp(posicao, dados.jogadores[i].posicao) == 0) {
            mostrar_jogadores(i);
            cont = 1;
        }
    }
    if (cont == 0) {
        printf("=============================================\n");
        printf("Nenhum jogador nesta posição encontrado\n");
        printf("=============================================\n");
    }
}


void busca_time_adversario(void)
{
    if (validar_qtd_partidas() == 0) {
        return;
    }
    
    string time_ad_user;

    getchar();
    printf("Digite o time adversario:\n");
    printf("::");
    fgets(time_ad_user, TAM, stdin);
    time_ad_user[strcspn(time_ad_user, "\n")] = '\0';

    for (int i = 0; i < dados.qtd_partidas; i++) {
        if(strcasecmp(time_ad_user, dados.parti[i].nome_time) == 0) {
            mostrar_partidas(i);
        }
    }
}

void jogador_maior_salario(void) 
{
    if (validar_qtd_jogadores() == 0) {
        return;
    }
    
    //Armazena o primeiro salario armazenado
    float maior_salario = dados.jogadores[0].salario;
    int ind = 0;

    for (int i = 1; i < dados.qtd_jogadores; i++) {
        //Compara com todos os outros
        if(dados.jogadores[i].salario > maior_salario) {
            //se for maior maior_salario recebe este valor
            maior_salario = dados.jogadores[i].salario;
            //Guarda o indice do do jogador que recebe o melhor salário
            ind = i;
        }
    }
    printf("Maior Salário\n");
    mostrar_jogadores(ind);
    printf("=============================================\n");

}

void filtro_salario(void)
{
    if (validar_qtd_jogadores() == 0) {
        return;
    }
    
    float salario_user_1;
    float salario_user_2;
    int cont = 0;

    printf("Digite o filtro de salario:\n");
    printf("Salário 1:");
    scanf("%f", &salario_user_1);
    printf("Salário 2:");
    scanf("%f", &salario_user_2);
    printf("=============================================\n");

    for (int i = 0; i < dados.qtd_jogadores; i++) {
        //Verifica se o jogador ainda está no clube
        if (strcmp(dados.jogadores[i].condicao, ativo) == 0 || strcmp(dados.jogadores[i].condicao, lesao) == 0) {
            if (dados.jogadores[i].salario > salario_user_1 & dados.jogadores[i].salario < salario_user_2) {
                mostrar_jogadores(i);
                cont = 1;
            }
        }    
    }

    if (cont == 0) {
        printf("Nenhum jogador encontrado nesta faixa salarial.\n");
        printf("=============================================\n");
    }
}
