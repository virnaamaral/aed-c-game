#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

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

    char descricao_exemplo[] = "texto exemplo";

    comodo1->prev = NULL;
    comodo1->next = comodo2;
    strcpy(comodo1->nome, "sala");
    strcpy(comodo1->descricao, descricao_exemplo);
    comodo1->itens_disponiveis = 5;

    comodo2->prev = comodo1;
    comodo2->next = comodo3;
    strcpy(comodo2->nome, "quarto");
    strcpy(comodo2->descricao, descricao_exemplo);
    comodo2->itens_disponiveis = 3;
    
    comodo3->prev = comodo2;
    comodo3->next = NULL;
    strcpy(comodo3->nome, "sotao");
    strcpy(comodo3->descricao, descricao_exemplo);
    comodo3->itens_disponiveis = 1;

    // printf("\nCONSEGUIU ALOCAR\n");
    // printf("comodo1: %s\ndescricao: %s\nitens dispo: %d\n", comodo1->nome, comodo1->descricao, comodo1->itens_disponiveis);
    // printf("\ncomodo2: %s\ndescricao: %s\nitens dispo: %d\n", comodo1->next->nome, comodo1->next->descricao, comodo1->next->itens_disponiveis);
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