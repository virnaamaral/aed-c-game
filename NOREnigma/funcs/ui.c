#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// #ifdef _WIN32
//     #include <windows.h>
// #else
//     #include <unistd.h>
// #endif

void limpa_tela() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

void pausa() {
    printf("\n\nPressione ENTER para continuar...\n\n");
    getchar();
}

void imprimir_com_pausa(char *mensagem, int pausa_ms) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        fputc(mensagem[i], stdout);
        fflush(stdout);
        pausa(pausa_ms);
    }
}

// imprime_com_pausa(mensagem, 100); 
// 100 pra texto de titulo, + lento
// 35 para falas

void menu_inicial(){
    printf("\n\t\t\tSEJA BEM VINDO AO\n\n");
    printf("              __   __     ______     ______                           \n");
    printf("             /\\ \"-.\\ \\   /\\  __ \\   /\\  == \\                  \n");
    printf("             \\ \\ \\-.  \\  \\ \\ \\/\\ \\  \\ \\  __<               \n");
    printf("              \\ \\_\\\"\\_ \\  \\ \\_____\\  \\ \\_\\ \\_\\          \n");
    printf("               \\/_/ \\/_/   \\/_____/   \\/_/ /_/                    \n");
    printf(" ______     __   __     __     ______     __    __     ______                                      \n");
    printf("/\\  ___\\   /\\ \"-.\\ \\   /\\ \\   /\\  ___\\   /\\ \"-./  \\   /\\  __ \\                      \n");
    printf("\\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\  \\ \\ \\__ \\  \\ \\ \\-./\\ \\  \\ \\  __ \\              \n");
    printf(" \\ \\_____\\  \\ \\_\\\"\\_ \\  \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\         \n");
    printf("  \\/_____/   \\/_/ \\/_/   \\/_/   \\/_____/   \\/_/  \\/_/   \\/_/\\/_/                          \n");
    printf("\n"); 

    printf("[1] - Iniciar \n");
    printf("[2] - Sobre\n");
    printf("[3] - Sair\n");
    printf("\n");

}

void sobre(){
    printf("Desenvolvido em 2023, NOREnigma eh um projeto para a cadeira de Algoritmos e Estrutura de Dados do terceiro periodo. Tinhamos a tarefa de criar um game totalmente do zero em C, tendo como enfoque alguma estrutura de dados de nossa escolha que foi abordada durante o periodo. Escolhemos utilizar listas duplamente encadeadas pela versatilidade e facilidade na manipulacao dos dados com ela.\n\nDEVS:\nPedro Monteiro\nVirna Amaral");
}