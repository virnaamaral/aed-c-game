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
//#include "include/puzzle1.h"
#include "include/puzzles.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif


int main(){

    int input_menu;
    setUtf8Encoding();
    limpa_tela();
    while(1){
        limpa_tela();
        menu_inicial();
        scanf("%d", &input_menu);

        if(input_menu == 1){
            historia();
            
            mapa *HeadMapaNOREnigma = NULL, *cursor_movimento = NULL;
            criar_mapa(&HeadMapaNOREnigma);
            cursor_movimento = HeadMapaNOREnigma;

            while(1){
                int input = 0;

                if(cursor_movimento->posicao == 1){
                    menu_sala();
                }else if (cursor_movimento->posicao == 2){
                    menu_quarto();
                }else if (cursor_movimento->posicao == 3){
                    puzzle5();
                }

                scanf("%d", &input);

                if(input == 1){
                    printf("%s", cursor_movimento->descricao);
                    pausa();
                }else if(input == 2 && cursor_movimento->posicao == 1){
                    movimentacao_mapa(2, &cursor_movimento, cursor_movimento->posicao);
                }else if(input == 2 && cursor_movimento->posicao == 2){
                    movimentacao_mapa(1, &cursor_movimento, cursor_movimento->posicao);
                }

            }

            // puzzle3();
        
            limpar_lista(&HeadMapaNOREnigma);
        
            HeadMapaNOREnigma = NULL;
            cursor_movimento = NULL;
        
        }else if(input_menu == 2){
            sobre();
            pausa();
        }else if(input_menu == 3){
            break;
        }

    }

    //puzzle1();
    //puzzle3();
    //puzzle5();


    return 0;
}
