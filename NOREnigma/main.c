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
#include "ui.h"
#include "structs.h"
#include "sorting.h"
#include "puzzles.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif


int main(){

    int input_menu;
    setUtf8Encoding();
    limpa_tela();
    // while(1){
    //     limpa_tela();
    //     menu_inicial();
    //     scanf("%d", &input_menu);
        
    //     if(input_menu == 1){
    //         historia();
    //         puzzle3();
    //     }else if(input_menu == 2){
    //         sobre();
    //         pausa();
    //     }else if(input_menu == 3){
    //         break;
    //     }

    // }

    // mapa *HeadMapaNOREnigma = NULL;
    // criar_mapa(&HeadMapaNOREnigma);

    // printlist(HeadMapaNOREnigma);

    // printf("%s\n", HeadMapaNOREnigma->nome);
    // printf("%d\n", HeadMapaNOREnigma->prev);

    // limpar_lista(&HeadMapaNOREnigma);

    puzzle5();

    return 0;
}
