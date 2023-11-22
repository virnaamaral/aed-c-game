#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"

void criar_mapa(mapa **HeadMapaNOREnigma){
    mapa *comodo1 = (mapa *)malloc(sizeof(mapa));
    mapa *comodo2 = (mapa *)malloc(sizeof(mapa));
    mapa *comodo3 = (mapa *)malloc(sizeof(mapa));
    
    if(comodo1 == NULL || comodo2 == NULL || comodo3 == NULL){
        printf("Problemas na alocação do mapa.\n");
        free(comodo1);
        free(comodo2);
        free(comodo3);
        exit(1);
    }

    (*HeadMapaNOREnigma) = comodo1;

    char descricao_sala[] = "\n\tO cômodo é consideravelmente grande. À sua direita, você vê um sofá pequeno, uma poltrona vermelha e uma televisão de tubo posicionada em cima de uma estante simples e pequena de madeira. À sua esquerda, você vê uma pequena mesa redonda de madeira com duas cadeiras e, em cima dela, um pequeno jarro de vidro transparente e algumas flores. Mais a frente da mesa, você também observa uma pia e um balcão grande, um fogão e geladeiras de aparência antiga, mas parecem funcionar. Entretanto, você vê algo que lhe chama a atenção. À esquerda do balcão, você vê uma grande porta de madeira com 3 lâmpadas apagadas e um conjunto de fios que parecem estar conectados a um faqueiro em cima do balcão. Diferente do habitual, as facas não estão encaixadas, mas sim, no balcão. Outro detalhe é que a escada para o sótão, que costumava ficar guardada, estava descida. Era possível ver o alçapão trancado por um cadeado.\n";
    char descricao_quarto[] = "\n\tO quarto é simples, mas nem por isso perde sua beleza. Você vê uma cama de casal grande, com uma cabeceira bem detalhada, a madeira parece ser de qualidade. Mais em frente, está um guarda roupa consideravelmente grande e, perto dele, pode-se ver uma penteadeira com alguns perfumes, maquiagens e uma caixa de remédios. Porém, ao lado da cama, existe um criado mudo com uma gaveta que possui buraco para chave.\n";
    char descricao_sotao[] = "\n\tO sótão é escuro e empoeirado, cheio de caixas e itens não utilizados na casa. O disjuntor pode ser visto do outro lado do cômodo. Você também vê uma janela e o vidro dela está tão sujo que não dá pra enxergar do lado de fora.\n";

    comodo1->prev = NULL;
    comodo1->next = comodo2;
    strcpy(comodo1->nome, "Sala");
    strcpy(comodo1->descricao, descricao_sala);
    comodo1->posicao = 1;

    comodo2->prev = comodo1;
    comodo2->next = comodo3;
    strcpy(comodo2->nome, "Quarto");
    strcpy(comodo2->descricao, descricao_quarto);
    comodo2->posicao = 2;
    
    comodo3->prev = comodo2;
    comodo3->next = NULL;
    strcpy(comodo3->nome, "Sótão");
    strcpy(comodo3->descricao, descricao_sotao);
    comodo3->posicao = 3;

    // printf("\nCONSEGUIU ALOCAR\n");
}

void movimentacao_mapa(int destino, mapa **cursor_movimento, int posicao_atual){
    if(destino == posicao_atual){
        printf("Você já está no comodo %d.\n", posicao_atual);
        return;
    }

    if(destino < 1 || destino > 3){
        printf("Destino inválido.\n");
        return;
    }

    while(destino > posicao_atual && (*cursor_movimento)->next != NULL){
        *cursor_movimento = (*cursor_movimento)->next;
        posicao_atual++;
    }

    while(destino < posicao_atual && (*cursor_movimento)->prev != NULL){
        *cursor_movimento = (*cursor_movimento)->prev;
        posicao_atual--;
    }

    if(posicao_atual == destino){
        printf("Movido para o comodo %s.\n", (*cursor_movimento)->nome);
    } else {
        printf("Não foi possível alcançar o destino %d.\n", destino);
    }
}


void limpar_lista(mapa **head){
    mapa *temp = (*head);

    while(temp->next != NULL){
        temp = temp->next;
    }

    while(temp->prev != NULL){
        free(temp->next);
        temp = temp->prev;
    }

    free(temp);
    *head = NULL;
    
    printf("\nLIMPOU O MAPA\n");
}

void printlist(mapa *head){
    while(head != NULL){
        printf("%s\n", head->nome);
        head = head->next;
    }

    if(head == NULL){
        printf("\nlista vazia\n");
    }

}