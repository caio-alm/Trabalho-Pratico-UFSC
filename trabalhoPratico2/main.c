#include <stdint.h>
#include "./include/menus.h"
#include "./include/type.h"
#include "./include/cadastro.h"
#include "./include/relatorios.h"
#include "./include/buscas.h"
#include "./include/arquivos_jogadores.h"
#include "./include/arquivos_partidas.h"


#define SAIR 0

int main()
{
    uint8_t opcao, sub_menu;
    int idade_max, idade_min;
    float salario_min, salario_max;
    string nome_jogador_user, posicao_user, nome_adversario, nome_arq;
    no_t *aux = NULL;
    desempenho_t indi;

    lista_t lista_jogadores;
    lista_jogos_t lista_partidas;


    inicializa_lista(&lista_jogadores);
    inicializa_lista_jogos(&lista_partidas);

    ler_jogadores_arquivo_binario("dados_jogadores.bin", &lista_jogadores);
    ler_partidas_arquivo_binario("dados_partidas.bin", &lista_partidas);



    do {
        opcao = menu_principal();

        switch (opcao) {
            case 1: 
                    do {
                        sub_menu = menu_cadastros();
                        switch(sub_menu) {
                            case 1: {
                                        no_t *novo = novo_jogador();
                                        inserir_jogador(&lista_jogadores, novo);
                                    }
                                    break;
                            
                            case 2: {
                                        no_jogos_t *nova_partida = novo_jogo(&lista_jogadores); 
                                        inserir_jogo(&lista_partidas, nova_partida);
                                    }
                                    break;
                        }

                    } while(sub_menu != SAIR);
                    
                    break;

            case 2:
                    do {
                        sub_menu = menu_relatorios();
                        switch (sub_menu) {
                            case 1: relatorio_jogadores(lista_jogadores.cabeca);
                                    break;

                            case 2:
                                    limpar_tela();
                                    msg_cabecalho("Relatório por idade");

                                    printf("Digite a idade menor: ");
                                    scanf("%d", &idade_min);
                                    printf("Digite a idade maior: ");
                                    scanf("%d", &idade_max);
                                    getchar();
                                    if(idade_min > idade_max){
                                        printf("Erro, Idade mínima maior que maxima\n");
                                        msg_press_enter();
                                        break;
                                    }

                                    relatorio_por_idade(lista_jogadores.cabeca, idade_min, idade_max);
                                    break;
                                
                            case 3: relatorio_lesionados(lista_jogadores.cabeca);
                                    break;

                            case 4: relatorio_vendidos(lista_jogadores.cabeca);
                                    break;

                            case 5: relatorio_vendas(lista_jogadores.cabeca);
                                    break;

                            case 6: 
                                    limpar_tela();
                                    msg_cabecalho("Relatorio de Salário");

                                    printf("Digite o 1 intervalo: ");
                                    scanf("%f", &salario_min);
                                    printf("Digite o 2 intervalo: ");
                                    scanf("%f", &salario_max);
                                    
                                    if(salario_min > salario_max){
                                        printf("Erro, Salário mínimo maior que maximo\n");
                                        msg_press_enter();
                                        break;
                                    }

                                    relatorio_salario(lista_jogadores.cabeca, salario_min, salario_max);
                                    break;

                            case 7: relatorio_partidas(lista_partidas.cabeca_jogos);
                                    break;

                            case 8: indi = aproveitamento(lista_partidas.cabeca_jogos);
                                    relatorio_aproveitamento(indi);
                                    msg_press_enter();
                                    break;

                            case 9: 
                                    printf("Digite o nome do time adversário: ");
                                    fgets(nome_adversario, T_STR, stdin);
                                    retirar_enter(nome_adversario);
                                    to_upper(nome_adversario);

                                    buscar_partidas_adversario(nome_adversario, lista_partidas.cabeca_jogos);

                                    break;
                                    

                        }
                    } while (sub_menu != SAIR);
                    break;

            case 3:
                    do {
                        sub_menu = menu_buscas();
                        switch(sub_menu) {
                            case 1: printf("Digite o nome do jogador desejado:");
                                    fgets(nome_jogador_user, T_STR, stdin);
                                    printf("\n");
                                    retirar_enter(nome_jogador_user);
                                    to_upper(nome_jogador_user);

                                    aux = buscar_jogador(nome_jogador_user, lista_jogadores.cabeca);

                                    if (aux) {
                                        mostrar_jogadores(aux);
                                        msg_press_enter();
                                    }
                                    else {
                                        printf("Nenhum jogador chamado %s cadastrado\n", nome_jogador_user);
                                        msg_press_enter();
                                    }
                                    
                                    break;

                            case 2: printf("Digite a posição desejada:");
                                    fgets(posicao_user, T_STR, stdin);
                                    retirar_enter(posicao_user);
                                    to_upper(posicao_user);

                                    buscar_posicao(posicao_user, lista_jogadores.cabeca);

                                    break;
                                    

                            case 3: msg_cabecalho("Jogador com maior salário");
                                    buscar_maior_salario(lista_jogadores.cabeca);
                                    msg_press_enter();
                                    break;

                            case 4: msg_cabecalho("Buscar partidas contra adversário");
                                    printf("Digite o nome do time adversário: ");
                                    fgets(nome_jogador_user, T_STR, stdin);
                                    retirar_enter(nome_jogador_user); 
                                    buscar_partidas_adversario(nome_jogador_user, lista_partidas.cabeca_jogos);
                                    break;
                                
                        }
                    } while (sub_menu != SAIR);
                    break;
            
            case 4: 
                    do {
                        sub_menu = menu_arquivos();
                        switch(sub_menu) {
                            case 1: limpar_tela();
                                    msg_cabecalho("Exportar jogadores para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);

                                    exportar_jogador_arquivo_texto(nome_arq, lista_jogadores.cabeca);
                                    msg_press_enter();

                                    break;

                            case 2: limpar_tela();
                                    msg_cabecalho("Exportar jogadores para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida (extensao .csv)? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);
                                    exportar_dados_jogadores_arquivo_csv(nome_arq, lista_jogadores.cabeca);
                                    msg_press_enter();
                                    break;

                            case 3: limpar_tela();
                                    msg_cabecalho("Exportar partidas para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);

                                    exportar_partidas_arquivo_texto(nome_arq, lista_partidas.cabeca_jogos);
                                    msg_press_enter();

                                    break;

                            case 4: limpar_tela();
                                    msg_cabecalho("Exportar partidas para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida (extensao .csv)? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);
                                    exportar_dados_partidas_arquivo_csv(nome_arq, lista_partidas.cabeca_jogos);
                                    msg_press_enter();
                                    break;



                        }    
                    } while(sub_menu != SAIR);
                    break;
        
        }
    } while (opcao != SAIR);

    if (!is_lista_players_vazia(lista_jogadores.cabeca)) {
        salvar_jogadores_arquivo_binario("dados_jogadores.bin", lista_jogadores.cabeca);
    }

    if (!is_lista_jogos_vazia(lista_partidas.cabeca_jogos)) {
        salvar_partidas_arquivo_binario("dados_partidas.bin", lista_partidas.cabeca_jogos);
    }



    return 0;
}
