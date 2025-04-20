#include "parser.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 256

int checar_expressao(FILE *input, FILE *output)
{
    char linha[64];
    char *tipo = malloc(4);
    char *valor = malloc(16);

    // Armazenar todos os valores numéricos
    int valores[MAX_TOKENS];
    int qtd_valores = 0;

    int operador = 1; // 1 = positivo, -1 = negativo
    bool esperando_numero = true;
    bool encontrou_numero = false;
    bool esperando_operador = false;

    while (fgets(linha, sizeof(linha), input))
    {
        if (strncmp(linha, "EOF", 3) == 0)
        {
            break;
        }

        sscanf(linha, "%3s(%15[^)])", tipo, valor);

        if (strcmp(tipo, "NUM") == 0)
        {
            if(qtd_valores == 0) {
                esperando_operador = true;
                encontrou_numero = true;    
            }

            if (!esperando_numero) {
                fprintf(stderr, "Erro de sintaxe: número inesperado após outro número\n");
                return -1;
            }

            int numero = atoi(valor) * operador;
            valores[qtd_valores++] = numero;
            operador = 1; // reseta para positivo para o próximo número
            esperando_numero = false;
        }
        else if (strcmp(tipo, "OPR") == 0)
        {
            esperando_operador = false;
            if (esperando_numero)
            {
                fprintf(stderr, "Erro de sintaxe: operador seguido de outro operador\n");
                return -1;
            }

            if (strcmp(valor, "+") == 0)
            {
                operador = 1;
            }
            else if (strcmp(valor, "-") == 0)
            {
                operador = -1;
            }
            esperando_numero = true;
        }
        else if (strcmp(tipo, "ERR") == 0)
        {
            fprintf(stderr, "Erro léxico detectado: %s\n", valor);
            return -1;
        }
    }

    if (!encontrou_numero) {
        fprintf(stderr, "Erro de sintaxe: expressão vazia\n");
        return -1;
    }
    if (esperando_numero) {
        fprintf(stderr, "Erro de sintaxe: expressão termina com operador\n");
        return -1;
    }
    if(esperando_operador) {
        fprintf(stderr, "Erro de sintaxe: não é uma expressão númerica\n");
        return -1;
    }

    // Gerar código assembler
    fprintf(output, "; Programa gerado automaticamente para somar/subtrair números\n");

    // Declarar todos os dados
    for (int i = 0; i < qtd_valores; i++)
    {
        fprintf(output, "DADO %d ; inicializa o end %d com o valor %d\n", valores[i], i, valores[i]);
    }

    // Gerar instruções
    fprintf(output, "LDA 0 ; Carrega o valor do endereço 0 no acumulador\n");
    for (int i = 1; i < qtd_valores; i++)
    {
        fprintf(output, "ADD %d ; Soma (ou subtrai) o valor do endereço %d ao acumulador\n", i, i);
    }
    fprintf(output, "STA 255 ; Armazena o resultado no endereço 255\n");
    fprintf(output, "HLT ; Para a execução\n");

    fclose(input);
    fclose(output);
    free(tipo);
    free(valor);
    return 0;
}
