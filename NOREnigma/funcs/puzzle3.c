#include <stdio.h>
#include <stdlib.h>
#include "../include/sorting.h"
#include "../include/structs.h"
#include "../include/ui.h"


void puzzle3(){

    setUtf8Encoding();
    limpa_tela();

    int A = 0, B = 0, C = 0, D = 0;
    int flag_circuito_1 = 0;
    int flag_circuito_2 = 0;
    int flag_circuito_3 = 0;

    printf("Ao se aproximar da porta, você nota que, em um balcão próximo, há quatro facas soltas ao lado de um faqueiro. Algo chama a sua atenção na parte direita do faqueiro, onde algo parece estar gravado. Na parte de cima do faqueiro, você vê as letras \"A\", \"B\", \"C\" e \"D\", cada uma ao lado de um respectivo buraco. Com tudo isso, lhe surge um pensamento: \n");
    pausa();
    limpa_tela();
    imprimir_com_pausa("\033[3m\"Interessante, esse desenho na lateral, essas letras... Tudo isso me lembra muito circuitos lógicos... É isso mesmo! Me lembro bem das aulas de Sistemas Digitais e Infraestrutura de Hardware que tive há alguns anos atrás durante minha mais recente graduação. Será que o faqueiro, essas facas e o circuito são a chave para abrir essa estranha porta?\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\"De fato, esse faqueiro não é comum. Vou tentar fazer alguns testes...\033[0m\"\n", 20);
    pausa();
    limpa_tela();

    while(flag_circuito_1 == 0){
        limpa_tela();
        printf("\t\t\tCIRCUITO 1:\n\nConsiderando o sistema binário (0 para \"desligado\" e 1 para \"ligado\") e as entradas lógicas A, B, C e D, que valor binário cada uma delas precisa ter para que a saída do circuito seja igual a 1?\n");
        printf("\nOBS: Insira cada número separado por espaços em branco e, na ordem alfabética (A B C D).\nEx.: (A = 1 B = 0 C = 0 D = 0)\nRESPOSTA A SER INSERIDA:\"1 0 0 0\"\n\n");

        printf("\n\t\tA ─────┐");
        printf("\n\t\t      AND ───┐");
        printf("\n\t\tB ─NOT─┘     │");
        printf("\n\t\t            AND─── [Saída]");
        printf("\n\t\tC ─NOT─┐     │");
        printf("\n\t\t      AND ───┘");
        printf("\n\t\tD ─────┘\n\n");
        
        printf("\nInsira a resposta para o circuito acima: ");

        //TODO temos que tratar a entrada das respostas, ele só aceita a resposta se tiver com as entradas separadas.
        scanf("%d %d %d %d", &A, &B, &C, &D);

        if(A == 1 && B == 0 && C == 0 && D == 1){
            flag_circuito_1 = 1;
        }else{
            limpa_tela();
            printf("\n\nApós inserir as facas, você espera que uma lâmpada se acenda, mas a porta permanece inalterada.\033[3m\"A sequência não está correta\"\033[0m, você conclui, retirando as facas para tentar outra combinação. A resposta certa ainda está à sua espera.\n\n");
            pausa();
            limpa_tela();
        }
    }

    limpa_tela();
    printf("\n\nVocê insere a sua resposta para o circuito e acerta! Uma das luzes da porta acende e uma luz verde pode ser enxergada.\nIsso parece promissor. Você percebe que o circuito começa a mudar magicamente, revelando um novo desenho.\n");
    imprimir_com_pausa("\n\033[3m\"Então era o que eu suspeitava. As facas servem para ligar um fio em outro dentro do faqueiro,\npermitindo a passagem de uma corrente...\033[0m\"\n", 20);
    pausa();
    limpa_tela();

    while(flag_circuito_2 == 0){
        printf("\t\t\tCIRCUITO 2:\n\nConsiderando o sistema binário (0 para \"desligado\" e 1 para \"ligado\") e as entradas lógicas A, B, C e D, que valor binário cada uma delas precisa ter para que a saída  do circuito seja igual a 1?\n");
        printf("\nOBS: Insira cada número separado por espaços em branco e, na ordem alfabética (A B C D).\nEx.: (A = 1 B = 0 C = 0 D = 0)\nRESPOSTA A SER INSERIDA:\"1 0 0 0\"\n\n");

        printf("\n\t\tA ──NOT──┐");
        printf("\n\t\t        AND ───┐");
        printf("\n\t\tB ───────┘     │");
        printf("\n\t\t              AND─── [Saída]");
        printf("\n\t\tC ──NOT──┐     │");
        printf("\n\t\t        AND ───┘");
        printf("\n\t\tD ───────┘\n\n");

        printf("\nInsira a resposta para o circuito acima: ");
        scanf("%d %d %d %d", &A, &B, &C, &D);

        if((A == 0 && B == 1 && C == 0 && D == 1) && flag_circuito_1 == 1){ //TODO substituir por while ou for
            flag_circuito_2 = 1;
        }else{
            limpa_tela();
            printf("\n\nApós inserir as facas, você espera que uma lâmpada se acenda, mas a porta permanece inalterada.\033[3m\"A sequência não está correta\"\033[0m, você conclui, retirando as facas para tentar outra combinação. A resposta certa ainda está à sua espera.");
            pausa();
            limpa_tela();
        }
    }

    limpa_tela();
    printf("\n\nA segunda luz da porta se acende. Resta apenas uma luz apagada quando você vê um outro circuito sendo formado.\n");
    pausa();
    limpa_tela();

    while(flag_circuito_3 == 0){
        printf("\t\t\tCIRCUITO 3:\nConsiderando o sistema binário (0 para \"desligado\" e 1 para \"ligado\") e as entradas lógicas A, B, C e D, que valor binário cada uma delas precisa ter para que a sua saída seja igual a 1?\n");
        printf("\nOBS: Insira cada número separado por espaços em branco e, na ordem alfabética (A B C D).\nEx.: (A = 1 B = 0 C = 0 D = 0)\nRESPOSTA A SER INSERIDA:\"1 0 0 0\"\n\n");
    
        printf("\n\t\tA ─────┐");
        printf("\n\t\t      AND ───┐");
        printf("\n\t\tB ─────┘     │");
        printf("\n\t\t          AND─── [Saída]");
        printf("\n\t\tC ─────┐     │");
        printf("\n\t\t      AND ───┘");
        printf("\n\t\tD ─NOT─┘\n\n");

        printf("\nInsira a resposta para o circuito acima: ");
        scanf("%d %d %d %d", &A, &B, &C, &D);

        if((A == 1 && B == 1 && C == 1 && D == 0) && flag_circuito_1 == 1 && flag_circuito_2 == 1){
            flag_circuito_3 = 1;
        }else{
            limpa_tela();
            printf("\n\nApós inserir as facas, você espera que uma lâmpada se acenda, mas a porta permanece inalterada.\n\"A sequência não está correta\", você conclui, retirando as facas para tentar outra combinação. A resposta certa ainda está à sua espera.");
            pausa();
            limpa_tela();
        }
    }

    printf("\n\nAo posicionar a última faca, você vê a última lâmpada se acender e, junto disso, você ouve um clique. Você decide girar a maçaneta e é surpreendida. Isso porque a porta que acabou de ser aberta é de um armário de ferramentas.\n");
    pausa();
    limpa_tela();
    //TODO terminar isso aqui, mas a versão ta feita, falta inserir parte da historia
}