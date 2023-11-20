//
// Created by pdrvsk on 11/19/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"
#include "include/ui.h"


// Função para descriptografar a mensagem em cifra de César
void descriptografarCesar(int chave);
int clarificaCesar();

int main(){
    int c=0;
    while(1){
        if(clarificaCesar() == 1){
            c++;
        }else{

        }
    }
    return 0;
}

int clarificaCesar() {
    int chave;


    imprimir_com_pausa("\n\tReconheces alguma dessas palavras?.\n", 35);
    imprimir_com_pausa("\n\tTal sansação estranha veio e consumiu o seu corpo, como um \033[3mDéjà vu\033[0m.\n", 35);
    for(int i = 1; i <= 26; i++){
        printf("%d - ", i);
        descriptografarCesar(i);
        printf("\n");

    }
    pausa();

    //scanf("%d");
    return 0;
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

