#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "sorting.h"

int bubblesort() {

    int array[5] = {5, 3, 7, 9, 1}, aux, resposta_bubblesort;

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5 - 1; j++) {
            if (i == 2) {
                resposta_bubblesort = array[1];
            }
            if (array[j] > array[j + 1]) {
                aux = array[j + 1];
                array[j + 1] = array[j];
                array[j] = aux;

                for (int k = 0; k < 5; k++) {
                    printf("%d ", array[k]);
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    return resposta_bubblesort;
}

int selectionsort() {
    int array[5] = {7, 5, 9, 3, 1}, aux, menor, selecionado, resposta_selectionsort;

    for (int i = 0; i < 5 - 1; i++) {
        selecionado = array[i];
        menor = i + 1;

        for (int j = i + 1; j < 5; j++) {
            if (array[menor] > array[j]) {
                menor = j;
            }
        }

        if (selecionado > array[menor]) {
            array[i] = array[menor];
            array[menor] = selecionado;
        }

        if (i == 3) {
            resposta_selectionsort = array[3];
        }
    }

    return resposta_selectionsort;
}

int insertionsort() {
    int array[5] = {7, 5, 9, 3, 1}, aux, resposta_insertionsort;
   
    for (int i = 1; i < 5; i++) {
        int j = i;

        while ((array[j] < array[j - 1]) && j > 0) {
            int aux = array[j - 1];
            array[j - 1] = array[j];
            array[j] = aux;
            --j;

            if (i == 1) {
                resposta_insertionsort = array[4];
            }
        }
    }

    return resposta_insertionsort;
}