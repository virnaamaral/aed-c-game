#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "structs.h"
#include "ui.h"

// ainda faltam detalhes aqui - falar da insercao das faquinhas
void puzzle3(){
    int A, B, C, D; 
    
    setUtf8Encoding();
    limpa_tela();
    printf("Ao aproximar-se da porta, você vê que, no balcão, existem 4 facas soltas próximas ao faqueiro. Algo parece estar gravado na parte direita dele. Chegando perto, lhe surge um pensamento: \n");
    imprimir_com_pausa("\033[3m\"Interessante, se parece muito com um circuito... Seria um circuito lógico? Com certeza são! Me lembro bem das aulas de Sistemas Digitais e Infraestrutura de Hardware que tive há alguns anos atrás durante minha mais recente graduação.\"\n", 20);
    imprimir_com_pausa("\n\"Será que o faqueiro, essas facas e o circuito são a resposta para abrir a porta estranha?...\033[0m\"\n", 20);
    pausa();
    limpa_tela();
    printf("Ao aproximar-se da porta, você vê que, no balcão, existem 4 facas soltas próximas ao faqueiro. Algo parece estar gravado na parte direita dele. Chegando perto, lhe surge um pensamento: \n");
    

    limpa_tela();

    printf("\n\tA ─────┐");
    printf("\n\t      AND ───┐");
    printf("\n\tB ─NOT─┘     │");
    printf("\n\t            AND─── [Saída]");
    printf("\n\tC ──NOT┐     │");
    printf("\n\t      AND ───┘");
    printf("\n\tD ─────┘");

    printf("\t\tCIRCUITO 1:\n\tConsiderando o sistema binário (0 para \"desligado\" e 1 para \"ligado\")e as \nentradas lógicas A, B, C e D, que valor binário cada uma delas precisa ter para que a sua saída seja igual a 1?\n");
    printf("OBS: Insira cada número separado por espaços em branco e, na ordem alfabética (A B C D).\nEx.: 0 0 0 0\n\n");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    fflsuh(stdin);

    if(A == 1 && B == 0 && C == 0 && D == 1){
        printf("Uma das luzes da porta acende e uma luz verde pode ser enxergada. Pelo visto, você esta no caminnho certo.\nLogo, você observa o circuito se movimentando, e percebe que o desenho está mudando. Você observa um novo circuito surgir quase que num passe de mágica.");
        
        printf("\n\tA ──NOT──┐");
        printf("\n\t        AND ───┐");
        printf("\n\tB ───────┘     │");
        printf("\n\t              AND─── [Saída]");
        printf("\n\tC ──NOT──┐     │");
        printf("\n\t        AND ───┘");
        printf("\n\tD ───────┘");

        printf("\n\n\t\tCIRCUITO 2:\n\tConsiderando o sistema binário (0 para \"desligado\" e 1 para \"ligado\")e as \nentradas lógicas A, B, C e D, que valor binário cada uma delas precisa ter para que a sua saída seja igual a 1?\n");
        printf("OBS: Insira cada número separado por espaços em branco e, na ordem alfabética (A B C D).\nEx.: 0 0 0 0\n\n");
        scanf("%d %d %d %d", &A, &B, &C, &D);
        fflsuh(stdin);

        if(A == 0 && B == 1 && C == 0 && D == 1){
            printf("A segunda luz da porta se acende. Resta apenas uma luz apagada quando você vê o outro circuito sendo formado.\n");
        
            printf("\n\tA ─────┐");
            printf("\n\t      AND ───┐");
            printf("\n\tB ─────┘     │");
            printf("\n\t          AND─── [Saída]");
            printf("\n\tC ─────┐     │");
            printf("\n\t      AND ───┘");
            printf("\n\tD ─NOT─┘");

            printf("\n\n\t\tCIRCUITO 3:\n\tConsiderando o sistema binário (0 para \"desligado\" e 1 para \"ligado\")e as \nentradas lógicas A, B, C e D, que valor binário cada uma delas precisa ter para que a sua saída seja igual a 1?\n");
            printf("OBS: Insira cada número separado por espaços em branco e, na ordem alfabética (A B C D).\nEx.: 0 0 0 0\n\n");
            scanf("%d %d %d %d", &A, &B, &C, &D);
            fflsuh(stdin);
        
            if(A == 1 && B == 1 && C == 1 && D == 0){
                printf("Ao posicionar a última faca, você vê a última lâmpada que restava apagada sendo acessa e, junto\ndisso, você ouve um clique. Você decide girar a maçaneta e é surpreendida. Isso porque a porta que acabou de ser aberta é de um armário de ferramentas.\n");

            }
        }

    }

}