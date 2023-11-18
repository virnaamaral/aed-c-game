#ifndef __STRUCTS_LIB__
#define __STRUCTS_LIB__

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
        char dica[350];
        char resposta[50];
        bool resolvido; 

    }puzzle;

    void criar_mapa(mapa **HeadMapaNOREnigma);
    void limpar_lista(mapa **head);
    void printlist(mapa *head);


#endif //__STRUCTS_LIB__