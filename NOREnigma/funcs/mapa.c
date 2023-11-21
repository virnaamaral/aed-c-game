#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"

void criar_mapa(mapa **HeadMapaNOREnigma){
    mapa *comodo1 = (mapa *)malloc(sizeof(mapa));
    mapa *comodo2 = (mapa *)malloc(sizeof(mapa));
    mapa *comodo3 = (mapa *)malloc(sizeof(mapa));
    
    if(comodo1 == NULL || comodo2 == NULL || comodo3 == NULL){
        printf("Problemas na alocação do mapa.\n");
        free(comodo1);
        free(comodo2);
        free(comodo3);
        exit(1);
    }

    (*HeadMapaNOREnigma) = comodo1;

    char descricao_sala[] = "O cômodo é consideravelmente grande. À sua direita, você vê um sofá pequeno, uma poltrona vermelha e uma televisão de tubo posicionada em cima de uma estante simples e pequena de madeira.\n\nÀ sua esquerda, você vê uma pequena mesa redonda de madeira com duas cadeiras e, em cima dela, um pequeno jarro de vidro transparente e com algumas flores. Mais a frente da mesa, você também observa uma pia e um balcão grande, um fogão e geladeiras de aparência antiga, mas parecem funcionar.\nEntretanto, você vê algo que lhe chama a atenção.\n\nÀ esquerda do balcão, você vê uma grande porta de madeira com 3 lâmpadas apagadas e um conjunto de fios que parecem estar conectados a um faqueiro em cima do balcão. Diferente do habitual, as facas não estão encaixadas, mas sim, no balcão.";
    char descricao_quarto[] = "";
    char descricao_sotao[] = "";

    comodo1->prev = NULL;
    comodo1->next = comodo2;
    strcpy(comodo1->nome, "sala");
    strcpy(comodo1->descricao, descricao_sala);
    comodo1->itens_disponiveis = 5;

    comodo2->prev = comodo1;
    comodo2->next = comodo3;
    strcpy(comodo2->nome, "quarto");
    strcpy(comodo2->descricao, descricao_quarto);
    comodo2->itens_disponiveis = 3;
    
    comodo3->prev = comodo2;
    comodo3->next = NULL;
    strcpy(comodo3->nome, "sotao");
    strcpy(comodo3->descricao, descricao_sotao);
    comodo3->itens_disponiveis = 1;

    // printf("\nCONSEGUIU ALOCAR\n");
}

void limpar_lista(mapa **head){
    mapa *temp = (*head);

    while(temp->next != NULL){
        temp = temp->next;
    }

    while(temp->prev != NULL){
        free(temp->next);
        temp = temp->prev;
    }

    free(temp);
    *head = NULL;
    
    printf("\nLIMPOU O MAPA\n");
}

void printlist(mapa *head){
    while(head != NULL){
        printf("%s\n", head->nome);
        head = head->next;
    }

    if(head == NULL){
        printf("\nlista vazia\n");
    }

}
