#include <stdio.h>
#include <locale.h>

// identificador de sistema operacional para
// melhorar compatibilidade do codigo com
// diferentes sistemas
// \/

#ifdef _WIN32
#include <windows.h> // para Sleep
#else
#include <unistd.h> // para usleep
#endif

// funcao de pausa temporal
// ?
void pausa(int milissegundos) {
#ifdef _WIN32
    Sleep(milissegundos);
#else
    usleep(milissegundos * 1000);
#endif
}

// funcao que imprime texto com pausa
// ?

void imprime_com_pausa(const char *mensagem, int pausa_ms) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        fputc(mensagem[i], stdout); // Imprime um caractere
        fflush(stdout);            // Garante que o caractere seja mostrado imediatamente
        pausa(pausa_ms);           // Espera antes de imprimir o prï¿½ximo
    }
}

int main() {

    // https://cursos.alura.com.br/forum/topico-problema-no-uso-da-biblioteca-locale-h-129586

    char *mensagem = "cabŠ‚ˆ‡a criaÆon‡a testando caraïct‚res especi is „ ‰ ‹ ”  . . . . .\n";
    imprime_com_pausa(mensagem, 40); // 100 ms de pausa entre cada caractere

    return 0;
}
