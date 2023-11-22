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

            int flag_ida_quarto = 0;
            int flag_puzzle_1 = 0;
            
            while(1){
                int input = 0;

                if(cursor_movimento->posicao == 1){
                    menu_sala(flag_ida_quarto);
                }else if (cursor_movimento->posicao == 2){
                    flag_ida_quarto = 1;
                    menu_quarto();
                    if(flag_puzzle_1 == 0){
                        puzzle1();
                        flag_puzzle_1 = 1;
                    }
                }else if (cursor_movimento->posicao == 3){
                    puzzle5();
                    break;
                }

                scanf("%d", &input);

                if(input == 1){
                    printf("%s", cursor_movimento->descricao);
                    pausa();
                }else if(input == 2 && cursor_movimento->posicao == 1){
                    movimentacao_mapa(2, &cursor_movimento, cursor_movimento->posicao);
                }else if(input == 2 && cursor_movimento->posicao == 2){
                    movimentacao_mapa(1, &cursor_movimento, cursor_movimento->posicao);
                }else if(cursor_movimento->posicao == 1 && input == 3 && flag_ida_quarto == 1){
                    puzzle3();
                    pos_puzzle3();
                    puzzle2(flag_puzzle_1);
                    movimentacao_mapa(3, &cursor_movimento, cursor_movimento->posicao);
                }
            }

            historia_fim();

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

    return 0;
}
