#include <stdio.h>
#include <stdint.h>
#include "neander/neander.h"

int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos está correto
    if (argc != 2) {
        printf("Uso: %s <arquivo_binario>\n", argv[0]);
        return 1;
    }

    // Abre o arquivo binário passado como argumento
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", argv[1]);
        return 1;
    }

    // Processa o arquivo
    int result = processarArquivo(input);
    fclose(input);

    if (result == -1) {
        printf("Arquivo inválido.\n");
    }

    return 0;
}