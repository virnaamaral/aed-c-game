#ifndef __STRUCTS_LIB__
#define __STRUCTS_LIB__

    #include <stdbool.h>

    typedef struct mapa{
        struct mapa *next;
        struct mapa *prev;
        
        char nome[30];
        char descricao[500];
        int posicao;

    }mapa;

    void criar_mapa(mapa **HeadMapaNOREnigma);
    void limpar_lista(mapa **head);
    void printlist(mapa *head);
    void movimentacao_mapa(int destino, mapa **cursor_movimento, int posicao_atual); // posical atual == cursor_movimentacao.posicao


#endif //__STRUCTS_LIB__