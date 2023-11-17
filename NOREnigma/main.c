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

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif


int main(){

    mapa *HeadMapaNOREnigma = NULL;
    criar_mapa(&HeadMapaNOREnigma);

    printf("%s\n", HeadMapaNOREnigma->nome);
    printf("%d", HeadMapaNOREnigma->prev);

    // limpa_tela();
    // menu_inicial();
    // Sleep(1000);
    // sobre();
    // historia();

    return 0;
}