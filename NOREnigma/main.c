/*

Compilar sistema:
gcc main.c ./funcs/*.c -I include -o main.exe

Rodar sistema:
./main.exe

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "include/ui.h"
#include "include/structs.h"
#include "include/sorting.h"
#include "include/puzzles.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif


int main(){

    // int input_menu;
    // setUtf8Encoding();
    // limpa_tela();
    
    // while(1){
    //     limpa_tela();
    //     menu_inicial();
    //     scanf("%d", &input_menu);
        
    //     if(input_menu == 1){
    //         historia();
    //         puzzle3();
    //         puzzle5();
    //     }else if(input_menu == 2){
    //         sobre();
    //         pausa();
    //     }else if(input_menu == 3){
    //         break;
    //     }

    // }

    mapa *HeadMapaNOREnigma = NULL, *cursor_movimento = NULL;
    criar_mapa(&HeadMapaNOREnigma);
    cursor_movimento = HeadMapaNOREnigma;

    printf("\n===============cursor=============\n");
    printf("\ncomodo cursor: %s\n", cursor_movimento->nome);

    printf("\n===============cursor=============\n");

    printf("\n****mapa****\n");

    printlist(HeadMapaNOREnigma);

    printf("\n****mapa****\n");


    printf("\n===============cursor=============\n");

    movimentacao_mapa(2, &cursor_movimento, cursor_movimento->posicao);

    movimentacao_mapa(1, &cursor_movimento, cursor_movimento->posicao);

    movimentacao_mapa(3, &cursor_movimento, cursor_movimento->posicao);


    printf("\ncomodo cursor: %s\n", cursor_movimento->nome);

    // movimentacao_mapa(3, &cursor_movimento, cursor_movimento->posicao);

    // printf("\ncomodo cursor: %s\n", cursor_movimento->nome);

    printf("\n===============cursor=============\n");

    limpar_lista(&HeadMapaNOREnigma);

    return 0;
}
