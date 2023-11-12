/*

Compilar sistema:
gcc main.c ./funcs/*.c -I include -o bin/saida.exe

Rodar sistema:
./bin/saida.exe

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "ui.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int main(){

    limpa_tela();
    // menu_inicial();
    // Sleep(1000);
    // sobre();
    historia();

    return 0;
}