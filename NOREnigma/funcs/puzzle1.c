#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"
#include "../include/ui.h"

// Função para descriptografar a mensagem em cifra de César
int clarificaCesar();
void descriptografarCesar(int chave);

int puzzle1() {
    int tentativas = 0;

    while(tentativas < 3) {
        if(!clarificaCesar()) {
            imprimir_com_pausa("\nDayane retomou a consciência...\n", 25);
            imprimir_com_pausa("\nDAYANE: Não sei o que aconteceu...\n", 35);
            return 0;
        } else {
            tentativas++;
            if (tentativas == 1) {
                imprimir_com_pausa("\n**Um arrepio foi sentido...\n", 35);
            } else if (tentativas == 2) {
                imprimir_com_pausa("\nDAYANE: ESTOU FICANDO MALUCA...\n", 35);
            }
        }
    }

    return 1;
}

int clarificaCesar() {
    int chave;

    imprimir_com_pausa("\n*Algo em sua cabeça tomou o controle do seu pensamento...\n", 35);
    imprimir_com_pausa("\nReconheces alguma dessas palavras?.\n", 35);
    imprimir_com_pausa("\n*Tal sensação estranha veio e consumiu o seu corpo...\n", 35);
    
    for(int i = 1; i <= 26; i++){
        printf("%d - ", i);
        descriptografarCesar(i);
        printf("\n");
    }

    imprimir_com_pausa("\n* A voz indaga novamente: VOCÊ RECONHECE ALGUMA DESSAS PALAVRAS? FALE LOGO!\nchave: ", 35);
    scanf("%d", &chave);

    return chave == 8 ? 0 : 1;
}

void descriptografarCesar(int chave) {

//TODO create a function to, basically, bruteforce all possibilities

/*    if (chave < 1 || chave > 26) {
        fprintf(stderr, "chave number is out of range");
        exit(EXIT_FAILURE);
    }*/

    char *inputFileName="folha_cifrada.txt";


    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Failed to open input file\n");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), inputFile)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (!isspace(line[i]) && !isblank(line[i]) && (line[i] != ',') != 0)
                printf("%c", (((line[i] - 97) + chave) % 26) + 97);
            else
                printf("%c", line[i]);
        }
    }

    fclose(inputFile);
}

