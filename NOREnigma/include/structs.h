#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mapa{
    struct mapa *next;
    struct mapa *prev;
    
    char nome[30];
    char descricao[500];
    int itens_disponiveis;

}mapa;

typedef struct item{
    struct mapa *next;
    struct mapa *prev;

    char nome[30];
    char descricao[500];

}item;

typedef struct puzzle{
    struct mapa *next;
    struct mapa *prev;

    char nome[30];
    char descricao[300];
    char dica[100];
    char resposta[50];
    bool resolvido; 

}puzzle;
