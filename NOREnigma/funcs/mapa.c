#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

mapa *criar_mapa(){
    mapa *comodo1, *comodo2, *comodo3 = (mapa *)malloc(sizeof(mapa));
    
    if(comodo1 == NULL || comodo2 == NULL || comodo3 == NULL){
        printf("deu problema na alocacao do mapa\n");
        free(comodo1);
        free(comodo2);
        free(comodo3);
        exit(1);
    }

    // char descricao_exemplo = "texto exemplo";

    comodo1->prev = NULL;
    comodo1->next = comodo2;
    strcpy(comodo1->nome, "sotao");
    strcpy(comodo1->descricao, "descricao exemplo");
    comodo1->itens_disponiveis = 5;

    comodo2->prev = comodo1;
    comodo2->next = comodo3;
    strcpy(comodo2->nome, "sala");
    strcpy(comodo2->descricao, "descricao 2");
    comodo2->itens_disponiveis = 3;
    
    comodo3->prev = comodo2;
    comodo3->next = NULL;
    strcpy(comodo3->nome, "quarto");
    strcpy(comodo3->descricao, "3 desc fofa");
    comodo3->itens_disponiveis = 1;

    return comodo1;
}

