#include "lexer.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tokenizar(FILE *input, FILE *output) {
    Token token_atual;
    char buffer[64];
    int i;

    while (true) {
        char c = fgetc(input);

        // Ignorar espaços em branco
        while (isspace(c)) {
            c = fgetc(input);
        }

        if (isdigit(c)) {
            // Lê número completo
            i = 0;
            while (isdigit(c)) {
                buffer[i++] = c;
                c = fgetc(input);
            }
            buffer[i] = '\0';
            ungetc(c, input); // devolve o caractere não-numérico

            token_atual.tipo.id = TOKEN_NUM;
            token_atual.tipo.description = "NUM";
            token_atual.valor = strdup(buffer);

        } else if (c == '+') {
            token_atual.tipo.id = TOKEN_OP;
            token_atual.tipo.description = "OPR";

            buffer[0] = c;
            buffer[1] = '\0';
            token_atual.valor = strdup(buffer);

        } else if (c == EOF) {
            token_atual.tipo.id = TOKEN_EOF;
            token_atual.tipo.description = "EOF";
            token_atual.valor = "";

            fprintf(output, "%s()\n", token_atual.tipo.description);
            break;

        } else {
            // Qualquer outro caractere é erro
            token_atual.tipo.id = TOKEN_ERROR;
            token_atual.tipo.description = "ERR";

            buffer[0] = c;
            buffer[1] = '\0';
            token_atual.valor = strdup(buffer);
        }

        fprintf(output, "%s(%s)\n", token_atual.tipo.description, token_atual.valor);
    }

    fclose(input);
    fclose(output);
    return 0;
}
