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
	        fflush(stdin);
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
    setUtf8Encoding();
    limpa_tela();
    printf("\tDesenvolvido em 2023, NOREnigma é um projeto para a cadeira de Algoritmos e Estrutura de Dados do terceiro período do curso de Ciência da Computação. Tínhamos a tarefa de criar um game totalmente do zero em C, tendo como enfoque alguma estrutura de dados de nossa escolha que foi abordada durante o período. Escolhemos utilizar listas duplamente encadeadas pela versatilidade e facilidade na movimentação pela lista e manipulação dos dados com ela.\n\nTime de Desenvolvimento:\nPedro Leite\nVirna Amaral\nEdüarda Agüiar\n");
}

void menu_sala(int flag_ida_quarto){
    limpa_tela();
    printf("\t\tAMBIENTE: SALA/COZINHA\n\n");
    printf("[1] - Descrever Ambiente\n");
    printf("[2] - Ir para o Quarto\n");
    if(flag_ida_quarto == 1){
        printf("[3] - Analisar a Porta\n\n");
    }
}

void menu_quarto(){
    limpa_tela();
    printf("\t\tAMBIENTE: QUARTO\n\n");
    printf("[1] - Descrever Ambiente\n");
    printf("[2] - Ir para a Sala\n\n");
}

void historia(){
    setUtf8Encoding();
    limpa_tela();
    imprimir_com_pausa("\t\t\033[3mFernando de Noronha\n\t\t1 de Junho de 2023\n\033[0m", 100);
    imprimir_com_pausa("\n\tNa tarde daquele pacato dia na ilha, uma sinfonia de ondas acariciava suavemente a costa de Fernando de Noronha. O Sol, em seu ápice, banhava as casas e as árvores frutíferas que cercavam a pequena comunidade. Duas amigas, como já era costume, saíam para colher frutas no entorno de suas casas, planejando um delicioso banquete refrescante de fim de tarde.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tClementina, uma senhorinha de 80 anos, radiante de vida e alegria, seus cabelos branquinhos como a neve, refletiam a luz do sol. Em sua cesta, repousavam os mais suculentos cajus, siriguelas em tons vibrantes de vermelho, pinhas apetitosas e folhas de camomila, ingrediente para o seu tão amado chazinho calmante. A cada passo cuidadoso, ela lembrava os inúmeros caminhos que percorreu ao longo de sua vida.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAo seu lado, Dayane, com seus 50 e poucos anos, exibia uma disposição que desafiava a idade. Seus cabelos cacheados dançavam ao sabor da brisa, sua pele parda reluzia sob o Sol, e seu sorriso delicado revelava uma personalidade doce e acolhedora. Ela acompanhava Clementina nestas caminhadas, um gesto de empatia e amizade.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mCLEMENTINA: \"O dia hoje está bem ensolarado, não é? Dias assim sempre me fazem lembrar do Reginaldo. Ele adorava o calor do Sol.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Ele deve ter sido mesmo muito especial. Consigo ver como seus olhos brilham ao falar dele.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nCLEMENTINA: \"Ah, Dayane, sinto muito a falta dele. Foi triste, mas ao menos ele não sofreu. Estávamos dormindo e, quando acordei, ele já tinha partido para estar com Deus.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Mas sempre vejo a senhora falando dele com um sorriso. Ele deve ter sido um ótimo marido.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nCLEMENTINA: \"Isso ele era, um maridão e tanto. O que acha de irmos voltando? Já temos frutas para uma semana inteira.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Concordo, vamos sim.\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tEnquanto retornavam, suas cestas repletas, conversavam sobre as fofocas da vizinhança, um passatempo sempre bem-vindo. No entanto, a conversa leve é subitamente interrompida quando Clementina começa a agir de forma estranha.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mCLEMENTINA: \"Qual a sua fruta favorita mesmo, Dayane? Se não me engano era mang-...\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tEla pausa abruptamente e para de andar. Dayane, surpresa, observa Clementina imóvel, segurando firmemente sua cesta.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"Por que parou? Aconteceu algo?\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tNão há resposta.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"Dona Clementina, a senhora está bem?\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAinda sem resposta, Clementina mantém uma expressao de terror em seu rosto. Dayane começa a desesperar-se, preocupada com a amiga.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"CLEMENTINA, FALE COMIGO! O QUE ACONTECEU?!\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAntes que Dayane pudesse terminar a frase, Clementina cai, como uma pedra, espalhando frutas pelo chão. Dayane, em desespero, grita por socorro. Aos poucos, pessoas se reunem ao redor delas, e logo o socorro chega, levando Clementina as pressas para o hospital.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tApesar de todos os esforcos, não foi possivel salvar Clementina, que já chegou sem vida ao hospital. A notícia chocou toda a ilha e sua família. O mais intrigante era que a causa exata do ocorrido permanecia um mistério. Mais tarde daquela noite, Dayane recebe uma ligação.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3m???: \"Alô?\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Alô, quem é?\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n???: \"Oi, sou Eliseu, primo de Clementina.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Do que precisa?\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nELISEU: \"Minha prima adorava mostrar fotos dela com Reginaldo. Acredito que ela já tenha compartilhado algumas com você.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: \"Sim, ela adorava relembrar os momentos com ele.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nELISEU: \"Ela era muito apegada a essas fotos, principalmente após a partida dele... Dayane, poderia escolher uma para o velório? Não temos coragem de entrar na casa dela agora...\"\n\033[0m", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tDayane hesitou, ponderando a dor e a nostalgia de tantas memorias compartilhadas com Clementina, e a estranha circunstancia de sua partida.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: \"Tudo bem, posso fazer isso.\"\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nELISEU: \"Muito obrigado, Dayane. Até mais.\"\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tNaquela noite, Dayane, reunindo a coragem que lhe restava, pegou a chave e dirigiu-se a casa amarela no fim de sua rua, a casa de Clementina. Parada diante da porta, um turbilhão de memórias e emoções a inundava, mas ela respirou fundo, determinada a fazer um último favor a sua querida amiga.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\tAssumindo a pele de Dayane, ajude-a a completar a sua tarefa: encontre uma foto de Clementina e Reginaldo para ser utilizada no velório.\n", 35);
    pausa();
    limpa_tela();
}
void historia_fim(){
    imprimir_com_pausa("\n\tRapidamente, processando tudo que aconteceu, Dayane foi até o quarto do \n\tcasal e achou uma foto dos dois, partindo, com toda sua agiliidade, \n\tao velório de Clementina, que estava acontecendo na casa de Eliseu.", 35);
    imprimir_com_pausa("\n\tChegando por lá entregou a foto para Eliseu que colocou em um lindo \n\tporta-retratos e apoiou ao lado do caixão.", 35);
    pausa();
    imprimir_com_pausa("\n\tDayane e Eliseu estavam conversando sobre o falecido casal, mostrando \n\ttodos os sentimentos envolvidos em ambos.", 35);
    imprimir_com_pausa("\n\t* Nesse momento, Eliseu, que estava bem abalado com a situação, resolveu \n\tcontar um segredo que ele guardou de todos por décadas.", 35);
    pausa();
    imprimir_com_pausa("\n\tELISEU: Dayane, preciso te contar uma coisa...", 35);
    pausa();
    imprimir_com_pausa("\n\tIsso sempre me esteve entalado, mas eu tinha minhas questões para não contar...\n"
                       "\tTu és filha de Clementina!\n", 35);
    pausa();
    imprimir_com_pausa("\n\t** Clementina da um pulo do caixão, assustando à todos que estavam presentes!", 35);
    pausa();
    imprimir_com_pausa("\n\tTodos ficaram sem entender nada, mas começaram a agradecer ao \nDivino e foram receber a benção de Clementina.", 35);
    imprimir_com_pausa("\n\tApós a sessão de abençoação, Clementina chamou Dayane para \nconversarem, pois Clementina não estava entendendo nada, nem como tinha parado no caixão, \nmuito menos a parte de ser mãe de Dayane.\n", 35);
    pausa();
    imprimir_com_pausa("\n\tAlgumas horas se passaram e as duas tinham ficado conversando e à procura de Eliseu, que, por algum motivo mistico, tinha sumido.", 35);
    pausa();
    imprimir_com_pausa("\n\tAté que: Em um determinado momento da conversa, Eliseu, apareceu ao \nlado delas, sem que nenhuma tivesse percebido.", 35);
    imprimir_com_pausa("\n\tNesse momento Eliseu estava explicando tudo que tinha acontecido \nentre as duas e revelou detalhes sobre a gestação de Clementina, ", 35);
    imprimir_com_pausa("\n\tDetalhes esses que não puderam ser ouvidos, apenas vistos pelas pessoas \nque ali estavam.", 35);
    imprimir_com_pausa("\n\tAlguns minutos de conversa depois, os 3 sairam sorridentes(até de mais)\nvagando pelas ruas e observando a vida como jamais fizeram.", 35);

}

