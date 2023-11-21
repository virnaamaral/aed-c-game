#include <stdio.h>
#include <stdlib.h>
#include "../include/sorting.h"
#include "../include/structs.h"
#include "../include/ui.h"


void puzzle2(int flag_puzzle_1){ // puzzle abrir sotao
    setUtf8Encoding();
    limpa_tela();

    int chave;
    if(flag_puzzle_1 == 1){
        imprimir_com_pausa("\tVocê pega o papel que encontrou na caixa nas mãos. As palavras estão embaralhadas. Você se lembra do evento estranho que aconteceu no quarto. \033[3m\"Será se tem algo haver com aquela tal de chave?\"\033[0m\n", 35);
        // pausa();
        // limpa_tela();
        printf("\nInsira a chave: ");
        scanf("%d", &chave);

        int resposta_bubblesort = 0, resposta_selectionsort = 0, resposta_insertionsort = 0;
        
        if(chave == 8){
            imprimir_com_pausa("\033[3m\"OITO!!... Que estranho, era como se algo dentro de mim soubesse que eu precisasse dizer esse número...\"\033[0m\n", 35);
            pausa();
            limpa_tela();
            imprimir_com_pausa("\tAs palavras magicamente começam a desembaralhar-se na folha. Quando você percebe, toma um susto. Pouco a pouco, você vê se formando um texto.\n", 35);
            pausa();
            limpa_tela();
            
            while(1){

                printf("\t\t\tO Enigma dos Números\n\n\t\033[3mNum sótão fechado, um mistério a desvendar,\n\tCom danças de números, um código a formar.\n\tBolhas que sobem, seleções que brilham ao luar,\n\tInserções precisas, um segredo a revelar.\033[0m\n");
                printf("\n\t\033[3mNa dança das bolhas, observe com atenção,\n\tNa segunda passada, o segundo é a solução.\n\tNa escolha seleta, a quarta rotação,\n\tRevela o quarto, com clara precisão\033[0m\n");
                printf("\n\t\033[3mNum sótão fechado, um mistério a desvendar,\n\tCom danças de números, um código a formar.\n\tBolhas que sobem, seleções que brilham ao luar,\n\tInserções precisas, um segredo a revelar.\033[0m\n");
                printf("\n\t\033[3mE na inserção final, sem mais demora,\n\tO quinto na primeira, chega sua hora.\n\tJunte os números, a chave agora,\n\tE o cadeado abre, sem mais demora.\033[0m\n\n");

                printf("\nInsira a resposta para a pergunta: ");
                printf("\nFormato de resposta: bubblesort selectionsort insertionsort\n");

                scanf("%d %d %d", &resposta_bubblesort, &resposta_selectionsort, &resposta_insertionsort);
                if(resposta_bubblesort == 3 && resposta_selectionsort == 7 && resposta_insertionsort == 1){
                    imprimir_com_pausa("\tDepois de escrever os números no papel, você ouve o cadeado que existia no alçapão do sótão cair no chão. Você decide subir as escadas e, ao final, a energia falta. Você lembra que o disjuntor fica justamente no sótão. Você abre o alçapão e entra.\n", 35);
                    pausa();
                    limpa_tela();
                    break;
                }else{
                    imprimir_com_pausa("\tVocê escreve os números no papel e nada muda. Eles brilham em vermelho e somem. Provavelmente algo está errado.\n", 35);
                    pausa();
                    limpa_tela();
                }
            }
        }
    }else{
        imprimir_com_pausa("\tVocê pega o papel que encontrou na caixa nas mãos. As palavras estão embaralhadas. Talvez você tenha que fazer uma visita ao quarto de Clementina...\n", 35);
        pausa();
        limpa_tela();
        return;
    }
}

// p1 - dec - libera oq? - 
// p2 - porta - CAIXA: foto e diario dos pais de reginaldo, e o hd com o arquivo do código amaldiçoado. FOLHA COM ESTE PUZZLE
// p3 - cadeado sotao (este arquivo) - libera o boss final
// p4 - charadas