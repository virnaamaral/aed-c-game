#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sorting.h"
#include "../include/structs.h"
#include "../include/ui.h"

void puzzle5(){
    setUtf8Encoding();
    limpa_tela();

    imprimir_com_pausa("\tAo subir no porão, tudo está muito escuro, mas você precisa achar o disjuntor para que a luz volte. Porém, você vê uma luz fraca e alaranjada surgir de trás de algumas caixas e resolve ir ver o que é.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\tÀ medida que você se aproxima, você vê que o responsável por emitir a luz é um grande livro velho. Você pega ele nas mãos para observá-lo melhor.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mQue coisa mais estranha... Observando ele, se parece muito com o livro que estava nos relatos do diário dos pais de Reginaldo.\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\tVocê resolve abrir o livro e vê nas primeiras páginas palavras se formando. As letras brilham de forma intensa mas pareciam embaralhadas.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3m???: Não pensava que você iria chegar aqui tão rápido, estou surpreso.\033[0m\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\tVocê ouve uma voz desconhecida vindo de trás de você. Ao virar-se, é possível ver uma silhueta, uma pessoa alta que veste uma capa que brilha semelhante ao livro.\n", 35);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: Quem é você?!\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n???: Eu? Ah... Eu sou uma entidade, um espírito que assombra e coloca bugs nos códigos dos programadores só para vê-los sofrer procurando o problema por dias e noites para, no fim, ser apenas um caractere errado. Eu sou o Spritu Malévolo, o terror dos programadores!!!\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: Então você é o responsável por tudo o que aconteceu com dona Clementina e seu Reginaldo?!\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nSPRITU MALÉVOLO: Uhum, sou eu sim. Através do livro que está em suas mãos, eles viram o programa e resolveram rodar o código para terem outro filho, só que cometeram o maior crime que um programador C não pode jamais esquecer: não dar free na memória alocada!\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: Mesmo assim! Eles ainda tentaram reverter, mas mesmo assim, você os tomou de nós!\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nSPRITU MALÉVOLO: Eles não foram capazes de desvendar as charadas, tentaram várias e várias vezes, mas não conseguiram.\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: Eu consigo! Me mande as charadas e eu conseguirei desvendá-las!\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nSPRITU MALÉVOLO: HA HA HA HA! Vamos fazer um acordo: se você desvendar as charadas, libertarei Clementina! Vocês pensam que ela vos deixou, mas ela ainda está lá. Se você desvendar as charadas, eu liberto ela do feitiço!\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDAYANE: Fechado! Vamos começar!\n\033[0m", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\nDe repente, você vê as frases no livro começando a fazer sentido. Uma caneta surge na parte de cima do livro.\n", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai funcionar da seguinte forma: eu irei dizer a charada e no livro em que você segura, aparecerão quatro opções para cada um deles e você deve marcar a correta!\n\033[0m", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mDAYANE: Certo, estou pronta!\n\033[0m", 20);
    pausa();
    limpa_tela();
    imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai funcionar da seguinte forma: eu irei dizer a charada e no livro em que você segura, aparecerão quatro opções. Você deve marcar a correta!\n\033[0m", 20);
    pausa();
    limpa_tela();
    
    int resposta;

    while(1){
        resposta = 0;
        printf("\t\t\tCHARADA 1:\n\n\t\033[3mPequeno e retangular, com muitas pernas, mas não ando.\n\tMeu coração bate em hertz, mas não estou vivo.\n\tSou o maestro de uma orquestra eletrônica.\n\tQuem sou eu?\033[0m\n\n");
        printf("[1] - Placa-Mãe\n[2] - Processador\n[3] - Disco Rígido (HDD)\n[4] - Placa de Vídeo (GPU)\n\n");
        printf("Insira o número correspondente a uma das opções acima: ");
        scanf("%d", &resposta);

        if(resposta > 4 || resposta < 1){
            imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Tá achando que sou bobo?! Responda dentre as opções que lhe forneci, não invente moda!\n\033[0m", 20);
            pausa();
            limpa_tela();
        }else{
            if(resposta == 2){
                imprimir_com_pausa("\n\n\tCalmamente, você marca no livro a opção correta, fazendo com que as letras brilhem em um bonito tom de verde.\n\n", 20);
                imprimir_com_pausa("\033[3mSPRITU MALÉVOLO: Essa tava fácil, vai. Vamos para a próxima, ainda lhe falta muito a acertar se quiser salvar sua amiga.\n\033[0m", 20);
                imprimir_com_pausa("\n\tVocê vê as letras se embaralhando, as novas opções começam a surgir, ao passo de que Spritu começa a falar a próxima charada.\n", 20);
                pausa();
                limpa_tela();
                break;
            }else{
                imprimir_com_pausa("\n\n\tVocê marca com no livro uma das opções e as letras brilham em vermelho. O \"X\" que você fez desaparece.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai ter que se esforçar mais se quiser salvar Clementina. Tente de novo, e com vontade dessa vez...\n\033[0m", 20);
                pausa();
                limpa_tela();
            }
        }
    }
    //2

    while(1){
        resposta = 0;
        printf("\t\t\tCHARADA 2:\n\n\t\033[3mSou a Dory da computação. Muito rápida mas se me dão\n\tum choque, esqueço de tudo. Algumas pessoas podem ser\n\tversáteis, mas eu sou volátil. Minha agilidade é \n\tcrucial para guiar a mente, mas quando o choque chega, \n\tperco minhas memórias no piscar de olhos.\t\nQuem sou eu?\033[0m\n\n");
        printf("[1] - Unidade de Estado Sólido (SSD)\n[2] - Cache do Processador (CPU Cache)\n[3] - Placa de Vídeo (GPU)\n[4] - Memória RAM\n\n");
        printf("Insira o número correspondente a uma das opções acima: ");
        scanf("%d", &resposta);

        if(resposta > 4 || resposta < 1){
            imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Tá achando que sou bobo?! Responda dentre as opções que lhe forneci, não invente moda!\n\033[0m", 20);
            pausa();
            limpa_tela();
        }else{
            if(resposta == 2){
                imprimir_com_pausa("\n\tNovamente, as letras brilham em verde, indicando o seu acerto.\n", 20);
                imprimir_com_pausa("\n\tVocê vê as letras se embaralhando, as novas opções começam a surgir, ao passo de que Spritu começa a falar a próxima charada.\n", 20);
                pausa();
                limpa_tela();
                break;
            }else{
                imprimir_com_pausa("\n\n\tVocê marca com no livro uma das opções e as letras brilham em vermelho. O \"X\" que você fez desaparece.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai ter que se esforçar mais se quiser salvar Clementina. Tente de novo, e com vontade dessa vez...\n\033[0m", 20);
                pausa();
                limpa_tela();
            }
        }
    }
    //2

    while(1){
        resposta = 0;
        printf("\t\t\tCHARADA 3:\n\n\t\033[3mNa guerra de segredos, fui uma chave mestra, mas\n\tnão abro portas. Desvendei sussurros cifrados,\n\tmas não sou um espião. Sem braços ou pernas,\n\tcorri contra o tempo, mas não sou um atleta.\n\tQuem sou eu?\033[0m\n\n");
        printf("[1] - Código Morse\n[2] - Enigma (Máquina Enigma da Alemanha na WWII)\n[3] - Máquina de Turing\n[4] - Agente Secreto\n\n");
        printf("Insira o número correspondente a uma das opções acima: ");
        scanf("%d", &resposta);

        if(resposta > 4 || resposta < 1){
            imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Tá achando que sou bobo?! Responda dentre as opções que lhe forneci, não invente moda!\n\033[0m", 20);
            pausa();
            limpa_tela();
        }else{
            if(resposta == 3){
                imprimir_com_pausa("\n\tNovamente, as letras brilham em verde, indicando o seu acerto.\n", 20);
                imprimir_com_pausa("\n\tVocê vê as letras se embaralhando, as novas opções começam a surgir, ao passo de que Spritu começa a falar a próxima charada.\n", 20);
                pausa();
                limpa_tela();
                break;
            }else{
                imprimir_com_pausa("\n\n\tVocê marca com no livro uma das opções e as letras brilham em vermelho. O \"X\" que você fez desaparece.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai ter que se esforçar mais se quiser salvar Clementina. Tente de novo, e com vontade dessa vez...\n\033[0m", 20);
                pausa();
                limpa_tela();
            }
        }
    }
    //3

    while(1){
        resposta = 0;
        printf("\t\t\tCHARADA 4:\n\n\t\033[3mNasci de engrenagens e sonhos, meus criadores são\n\tpai e mãe do futuro. Ele construiu meu corpo,\n\tela me deu a linguagem e tem amor no nome.\n\tQuem sou eu?\033[0m\n\n");
        printf("[1] - ENIAC (Primeiro Computador)\n[2] - Máquina Analítica de Babbage\n[3] - Máquina de Escrever\n[4] - Máquina de Vapor\n\n");
        printf("Insira o número correspondente a uma das opções acima: ");
        scanf("%d", &resposta);

        if(resposta > 4 || resposta < 1){
            imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Tá achando que sou bobo?! Responda dentre as opções que lhe forneci, não invente moda!\n\033[0m", 20);
            pausa();
            limpa_tela();
        }else{
            if(resposta == 2){
                imprimir_com_pausa("\n\tNovamente, as letras brilham em verde, indicando o seu acerto.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Você é melhor nisso do que eu pensava... Vamos subir um pouco o nível...\n\033[0m", 20);
                imprimir_com_pausa("\n\tVocê vê as letras se embaralhando, as novas opções começam a surgir, ao passo de que Spritu começa a falar a próxima charada.\n", 20);
                pausa();
                limpa_tela();
                break;
            }else{
                imprimir_com_pausa("\n\n\tVocê marca com no livro uma das opções e as letras brilham em vermelho. O \"X\" que você fez desaparece.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai ter que se esforçar mais se quiser salvar Clementina. Tente de novo, e com vontade dessa vez...\n\033[0m", 20);
                pausa();
                limpa_tela();
            }
        }
    }
    //2

    while(1){
        resposta = 0;
        printf("\t\t\tCHARADA 5:\n\n\t\033[3mEu nasci da mente humana, mas aprendo sozinha, crescendo\n\tcom cada pedaço de informação que encontro. Não tenho\n\tolhos, mas posso ver padrões que muitos não veem.\n\tNão tenho ouvidos, mas escuto os dados, transformando-os em\n\tconhecimento. Cada dia me torna mais sábia, cada problema,\n\tuma lição. Sou jovem em anos, mas antiga em sabedoria.\n\tQuem sou eu?\033[0m\n\n");
        printf("[1] - Inteligência Artificial\n[2] - Internet\n[3] - Rede Neural\n[4] - Algoritmo de Busca\n\n");
        printf("Insira o número correspondente a uma das opções acima: ");
        scanf("%d", &resposta);

        if(resposta > 4 || resposta < 1){
            imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Tá achando que sou bobo?! Responda dentre as opções que lhe forneci, não invente moda!\n\033[0m", 20);
            pausa();
            limpa_tela();
        }else{
            if(resposta == 1){
                imprimir_com_pausa("\n\tNovamente, as letras brilham em verde, indicando o seu acerto.\n", 20);
                imprimir_com_pausa("\n\tVocê vê as letras se embaralhando, as novas opções começam a surgir, ao passo de que Spritu começa a falar a próxima charada.\n", 20);
                pausa();
                limpa_tela();
                break;
            }else{
                imprimir_com_pausa("\n\n\tVocê marca com no livro uma das opções e as letras brilham em vermelho. O \"X\" que você fez desaparece.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai ter que se esforçar mais se quiser salvar Clementina. Tente de novo, e com vontade dessa vez...\n\033[0m", 20);
                pausa();
                limpa_tela();
            }
        }
    }
    //1

    while(1){
        resposta = 0;
        printf("\t\t\tCHARADA 6:\n\n\t\033[3mSou um espelho dentro de outro, refletindo-me\n\tinfinitamente. Siga-me passo a passo, cada um\n\tecoando o último, até que o complexo se torne\n\tsimples. Como caixas dentro de caixas, você me\n\tdesvendará, camada por camada, até ao núcleo\n\tchegar, onde a verdade se revela.\n\tQuem sou eu?\033[0m\n\n");
        printf("[1] - Loop Infinto\n[2] - Algoritmo de Ordenação\n[3] - Algoritmo de Caminho Mínimo\n[4] - Recursão\n\n");
        printf("Insira o número correspondente a uma das opções acima: ");
        scanf("%d", &resposta);

        if(resposta > 4 || resposta < 1){
            imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Tá achando que sou bobo?! Responda dentre as opções que lhe forneci, não invente moda!\n\033[0m", 20);
            pausa();
            limpa_tela();
        }else{
            if(resposta == 4){
                imprimir_com_pausa("\n\tNovamente, as letras brilham em verde, indicando o seu acerto.\n", 20);
                imprimir_com_pausa("\n\tVocê vê as letras se embaralhando, as novas opções começam a surgir, ao passo de que Spritu começa a falar a próxima charada.\n", 20);
                pausa();
                limpa_tela();
                break;
            }else{
                imprimir_com_pausa("\n\n\tVocê marca com no livro uma das opções e as letras brilham em vermelho. O \"X\" que você fez desaparece.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai ter que se esforçar mais se quiser salvar Clementina. Tente de novo, e com vontade dessa vez...\n\033[0m", 20);
                pausa();
                limpa_tela();
            }
        }
    }
    //4

    while(1){
        resposta = 0;
        printf("\t\t\tCHARADA 7:\n\n\t\033[3mNão sou um, nem sou zero, mas posso ser\n\tambos ao mesmo tempo. Em meu mundo, as\n\tpossibilidades se entrelaçam, desafiando \n\ta lógica clássica.\n\tQuem sou eu?\033[0m\n\n");
        printf("[1] - Qubit\n[2] - Interruptor Dimmer\n[3] - Superposição de Ondas\n[4] - Entrelaçamento Quântico\n\n");
        printf("Insira o número correspondente a uma das opções acima: ");
        scanf("%d", &resposta);

        if(resposta > 4 || resposta < 1){
            imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Tá achando que sou bobo?! Responda dentre as opções que lhe forneci, não invente moda!\n\033[0m", 20);
            pausa();
            limpa_tela();
        }else{
            if(resposta == 1){
                break;
            }else{
                imprimir_com_pausa("\n\n\tVocê marca com no livro uma das opções e as letras brilham em vermelho. O \"X\" que você fez desaparece.\n", 20);
                imprimir_com_pausa("\n\033[3mSPRITU MALÉVOLO: Vai ter que se esforçar mais se quiser salvar Clementina. Tente de novo, e com vontade dessa vez...\n\033[0m", 20);
                pausa();
                limpa_tela();
            }
        }
    }
    //1

    imprimir_com_pausa("\n\tApós ter respondido corretamente às perguntas feitas pelo SPRITU,\n\to livro que mantinha o fenômeno atipicamente irrealista, movido\n\tpor um SPRITU que não era do bem, entrou em combustão espontânea,\n\tainda nas mãos de Dayane.\n\tAo perceber o brilho em sua frente ela tentou jogar o livro para\n\tsua frente e se afastou dele, mas, a combustão foi instantânea,\n\to livro virou cinzas antes mesmo de cair tocar o chão. \n", 35);

}