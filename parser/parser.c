#include "parser.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 256

int checar_expressao(FILE* input, FILE* output) {
    char linha[64];
    char* tipo = malloc(4);
    char* valor = malloc(16);

    // Armazenar todos os valores numéricos
    char valores[MAX_TOKENS][16];
    int qtd_valores = 0;

    // Primeira passada: coletar todos os NUM
    while (fgets(linha, sizeof(linha), input)) {
        if (strncmp(linha, "EOF", 3) == 0) {
            break;
        }

        // Lê da string 'linha' o tipo do token (até 3 letras antes do parêntese)
        // e o valor do token (até 15 caracteres dentro dos parênteses),
        // armazenando-os nas variáveis 'tipo' e 'valor', respectivamente.
        // Exemplo: de "NUM(3)" -> tipo = "NUM", valor = "3"
        sscanf(linha, "%3s(%15[^)])", tipo, valor);

        if (strcmp(tipo, "NUM") == 0) {
            strcpy(valores[qtd_valores], valor);
            qtd_valores++;
        } else if (strcmp(tipo, "OPR") == 0) {
            if (strcmp(valor, "+") != 0) {
                fprintf(stderr, "Operador não suportado: %s\n", valor);
                return -1;
            }
        } else if (strcmp(tipo, "ERR") == 0) {
            fprintf(stderr, "Erro léxico detectado: %s\n", valor);
            return -1;
        }
    }

    // Gerar código assembler
    fprintf(output, "; Programa gerado automaticamente para somar números\n");

    // Declarar todos os dados
    for (int i = 0; i < qtd_valores; i++) {
        fprintf(output, "DADO %s ; inicializa o end %d com o valor %s\n", valores[i], i, valores[i]);
    }

    // Gerar instruções
    fprintf(output, "LDA 0 ; Carrega o valor do endereço 0 no acumulador\n");
    for (int i = 1; i < qtd_valores; i++) {
        fprintf(output, "ADD %d ; Soma o valor do endereço %d ao acumulador\n", i, i);
    }
    fprintf(output, "STA 255 ; Armazena o resultado no endereço 255\n");
    fprintf(output, "HLT ; Para a execução\n");

    fclose(input);
    fclose(output);
    free(tipo);
    free(valor);
    return 0;
}
