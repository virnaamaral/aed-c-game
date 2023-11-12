#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
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
        fputc(mensagem[i], stdout);
        fflush(stdout);
        
        #ifdef _WIN32
            Sleep(pausa_ms);
        #else
            usleep(pausa_ms * 1000);
        #endif
    }
}

// imprime_com_pausa(mensagem, 100); 
// 100 pra texto de titulo, + lento
// 35 para falas

void menu_inicial(){
    printf("\n\t\t      SEJA BEM VINDO AO\n\n");
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
    printf("\tDesenvolvido em 2023, NOREnigma eh um projeto para a cadeira de Algoritmos e Estrutura de Dados do terceiro periodo.\n");
    printf("Tinhamos a tarefa de criar um game totalmente do zero em C, tendo como enfoque alguma estrutura de dados de nossa escolha\n");
    printf("que foi abordada durante o periodo. Escolhemos utilizar listas duplamente encadeadas pela versatilidade e facilidade na\n");
    printf("manipulacao dos dados com ela.\n\nTIME:\nPedro Monteiro\nVirna Amaral\nEduarda Aguiar\n");
}

void historia(){

    imprimir_com_pausa("\t\t\033[3mFernando de Noronha\n\t\t1 de Junho de 2023\n\033[0m", 100);
    imprimir_com_pausa("\n\tNa tarde daquele pacato dia na ilha, uma sinfonia de ondas acariciava suavemente a costa de Fernando de Noronha. O Sol, em seu apice, banhava as casas e as arvores frutiferas que cercavam a pequena comunidade. Duas amigas, como ja era costume, saiam para colher frutas no entorno de suas casas, planejando um delicioso banquete refrescante de fim de tarde.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tClementina, uma senhorinha de 80 anos, radiante de vida e alegria, seus cabelos branquinhos como a neve, refletiam a luz do sol. Em sua cesta, repousavam os mais suculentos cajus, siriguelas em tons vibrantes de vermelho, pinhas apetitosas e folhas de camomila, ingrediente para o seu tao amado chazinho calmante. A cada passo cuidadoso, ela lembrava os inumeros caminhos que percorreu ao longo de sua vida.", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAo seu lado, Dayane, com seus 50 e poucos anos, exibia uma disposicao que desafiava a idade. Seus cabelos cacheados dancavam ao sabor da brisa, sua pele parda reluzia sob o Sol, e seu sorriso delicado revelava uma personalidade doce e acolhedora. Ela acompanhava Clementina nestas caminhadas, um gesto de empatia e amizade.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mCLEMENTINA: \"O dia hoje esta bem ensolarado, nao eh? Dias assim sempre me fazem lembrar do Reginaldo. Ele adorava o calor do Sol.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Ele deve ter sido mesmo muito especial. Consigo ver como seus olhos brilham ao falar dele.\"\n", 20);
    pausa();
    limpa_tela();

    
}