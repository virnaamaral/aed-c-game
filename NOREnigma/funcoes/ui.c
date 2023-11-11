#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifdef _WIN32
    #include <windows.h> // para Sleep
#else
    #include <unistd.h> // para usleep
#endif

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
        fputc(mensagem[i], stdout); // Imprime um caractere
        fflush(stdout);            // Garante que o caractere seja mostrado imediatamente
        pausa(pausa_ms);           // Espera antes de imprimir o pr�ximo
    }
}

//imprime_com_pausa(mensagem, 100); 
// 100 pra texto de titulo, + lento
// 35 para falas

void menu_inicial(){
    

    printf("              __   __     ______     ______                           \n");
    printf("             /\\ \"-.\\ \\   /\\  __ \\   /\\  == \\                  \n");
    printf("             \\ \\ \\-.  \\  \\ \\ \\/\\ \\  \\ \\  __<               \n");
    printf("              \\ \\_\\\"\\_ \\  \\ \\_____\\  \\ \\_\\ \\_\\          \n");
    printf("               \\/_/ \\/_/   \\/_____/   \\/_/ /_/                    \n");
    printf(" ______     __   __     __     ______     __    __     ______                                      \n");
    printf("/\\  ___\\   /\\ \"-.\\ \\   /\\ \\   /\\  ___\\   /\\ \"-./  \\   /\\  __ \\                                     \n");
    printf("\\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\  \\ \\ \\__ \\  \\ \\ \\-./\\ \\  \\ \\  __ \\                                    \n");
    printf(" \\ \\_____\\  \\ \\_\\\"\\_ \\  \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\       \n");
    printf("  \\/_____/   \\/_/ \\/_/   \\/_/   \\/_____/   \\/_/  \\/_/   \\/_/\\/_/                                   \n");
    printf("\n"); 



}