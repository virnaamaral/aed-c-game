#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <termios.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <curses.h>
    int kbhit(void){
    struct termios oldt, new_t;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);

    new_t = oldt;
    new_t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF){
        ungetc(ch, stdin);
        return 1;
    }
    return 0;

}

#endif

void setUtf8Encoding() {
    #ifdef _WIN32
    system("chcp 65001"); // Configura o código de página para UTF-8 no Windows
    #else
    printf("\e[1;1H\e[2J"); // Limpa a tela no Linux
    #endif
}

void limpa_tela() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void pausa() {
    printf("\nPressione ENTER para continuar...\n");
    limpar_buffer_entrada();
    getchar();
}

void imprimir_com_pausa(char *mensagem, int pausa_ms) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        fputc(mensagem[i], stdout);
        fflush(stdout);

        #ifdef _WIN32
            if (kbhit()) {
                fflush(stdin);
                printf("%s", &mensagem[i+1]);
            break;
        }

        #else
            if(kbhit()){
	            while(kbhit()){
		        getchar();
	            }
	        printf("%s", &mensagem[i+1]);
	      break;
	    }
	    //usleep(pausa_ms * 1000);

        #endif

	
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
    setUtf8Encoding();
    imprimir_com_pausa("éçççÀaaslkjü", 100);

    imprimir_com_pausa("\t\t\033[3mFernando de Noronha\n\t\t1 de Junho de 2023\n\033[0m", 100);
    imprimir_com_pausa("\n\tNa tarde daquele pacato dia na ilha, uma sinfonia de ondas acariciava suavemente a costa de Fernando de Noronha. O Sol, em seu apice, banhava as casas e as arvores frutiferas que cercavam a pequena comunidade. Duas amigas, como ja era costume, saiam para colher frutas no entorno de suas casas, planejando um delicioso banquete refrescante de fim de tarde.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tClementina, uma senhorinha de 80 anos, radiante de vida e alegria, seus cabelos branquinhos como a neve, refletiam a luz do sol. Em sua cesta, repousavam os mais suculentos cajus, siriguelas em tons vibrantes de vermelho, pinhas apetitosas e folhas de camomila, ingrediente para o seu tao amado chazinho calmante. A cada passo cuidadoso, ela lembrava os inumeros caminhos que percorreu ao longo de sua vida.\n", 35);
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
    imprimir_com_pausa("\nCLEMENTINA: \"Ah, Dayane, sinto muito a falta dele. Foi triste, mas ao menos ele nao sofreu. Estavamos dormindo e, quando acordei, ele ja tinha partido para estar com Deus.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Mas sempre vejo a senhora falando dele com um sorriso. Ele deve ter sido um otimo marido.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nCLEMENTINA: \"Isso ele era, um maridao e tanto. O que acha de irmos voltando? Acho que ja temos frutas para uma semana inteira.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Concordo, vamos sim.\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tEnquanto retornavam, suas cestas repletas, conversavam sobre as fofocas da vizinhanca, um passatempo sempre bem-vindo. No entanto, a conversa leve eh subitamente interrompida quando Clementina comeca a agir de forma estranha.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mCLEMENTINA: \"Qual a sua fruta favorita mesmo, Dayane? Se nao me engano era mang-...\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tEla pausa abruptamente e para de andar. Dayane, surpresa, observa Clementina imovel, segurando firmemente sua cesta.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"Por que parou? Aconteceu algo?\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tNao ha resposta.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"Dona Clementina, a senhora esta bem?\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAinda sem resposta, Clementina mantem uma expressao de terror em seu rosto. Dayane comeca a desesperar-se, preocupada com a amiga.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"CLEMENTINA, FALE COMIGO! O QUE ACONTECEU?!\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAntes que Dayane pudesse terminar a frase, Clementina cai, como uma pedra, espalhando frutas pelo chao. Dayane, em desespero, grita por socorro. Aos poucos, pessoas se reunem ao redor delas, e logo o socorro chega, levando Clementina as pressas para o hospital.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tApesar de todos os esforcos, nao foi possivel salvar Clementina. A noticia chocou toda a ilha e sua familia. O mais intrigante era que a causa exata do ocorrido permanecia um misterio. Mais tarde daquela noite, Dayane recebe uma ligacao.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3m???: \"Alo?\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Alo, quem eh?\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n???: \"Oi, sou Eliseu, primo de Clementina.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"O que precisa?\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nELISEU: \"Minha prima adorava mostrar fotos dela com Reginaldo. Acredito que ela ja tenha compartilhado algumas com voce.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Sim, ela adorava relembrar os momentos com ele.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nELISEU: \"Ela era muito apegada a essas fotos, principalmente apos a partida dele... Dayane, poderia escolher uma para o velorio? Nao temos coragem de entrar na casa dela agora...\"\n\033[0m", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tDayane hesitou, ponderando a dor e a nostalgia de tantas memorias compartilhadas com Clementina, e a estranha circunstancia de sua partida.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"Tudo bem, posso fazer isso.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nELISEU: \"Muito obrigado, Dayane. Ate mais.\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tNaquela noite, Dayane, reunindo a coragem que lhe restava, pegou a chave e dirigiu-se a casa amarela no fim de sua rua, a casa de Clementina. Parada diante da porta, um turbilhao de memorias e emocoes a inundava, mas ela respirou fundo, determinada a fazer um ultimo favor a sua querida amiga.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAssumindo a pele de Dayane, ajude-a a completar a sua tarefa: encontre uma foto de Clementina e Reginaldo para ser utilizada no velorio.\n", 35);
    pausa();
    limpa_tela();
}

