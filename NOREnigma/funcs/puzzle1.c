//
// Created by pdrvsk on 11/19/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"
#include "../include/ui.h"


// Função para descriptografar a mensagem em cifra de César
int clarificaCesar();
void descriptografarCesar(int chave);


int puzzle1(){
    int c=1;
    while(1 && c != 3){
        if(!clarificaCesar() ){
            imprimir_com_pausa("\nDayane retomou a consciência e percebeu que o tempo tinha passado apenas na mente dela, pois não fazia um minuto que estava por ali...\n", 25);
            return 0;
        }else{
            if(c == 1)
                imprimir_com_pausa("\n**Um arrepio foi sentido...\nPercorreu toda sua espinha e Dayane se via paralisada.\nMas por algum motivo ela ficou estatica, travada e decidiu ver novamente as palavras estranhas que tinham aparecido para ela...\n", 35);
            else if(c == 2)
                imprimir_com_pausa("\nDAYANE: ESTOU FICANDO MALUCA, ISSO SIM!\n NÃO TENHO IDÉIA DO QUE ESTÁ ACONTECENDO,\n QUE LUGAR MALUCO!\n", 35);
            else
                imprimir_com_pausa("\nDAYANE: Não sei o que aconteceu...\n * Que dor de cabeça danada", 35);
                return 1;
            c++;
        }
    }
    return 0;
}


int clarificaCesar() {
    int chave;


    imprimir_com_pausa("\n*Algo em sua cabeça tomou o controle do seu pensamento e elaborou o seguinte questionamento...\n", 35);
    imprimir_com_pausa("\nReconheces alguma dessas palavras?.\n", 35);
    imprimir_com_pausa("\n*Tal sansação estranha veio e consumiu o seu corpo, como um \033[3mDéjà vu\033[0m.\n", 35);
    pausa();
    for(int i = 1; i <= 26; i++){
        printf("%d - ", i);
        descriptografarCesar(i);
        printf("\n");

    }
    imprimir_com_pausa("\n* Tal voz indagou novamente, VOCÊ RECONHECE ALGUMA DESSAS PALAVRAS ? QUAIS ? FALE LOGO! \nchave: ", 35);
    printf("\0");
    scanf("%d\n", &chave);

    pausa();

    if(chave == 6)
        return 0;
    else
        return 1;
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

