#include <stdio.h>
#include <stdlib.h>

// Define o tamanho da fita de memória usada pela linguagem Brainfuck
#define TAPE_SIZE 30000

int main() {
    // Cria a fita de memória com 30.000 células, todas inicializadas com zero
    char tape[TAPE_SIZE] = {0};

    // Ponteiro que aponta para a célula atual da fita
    char *ptr = tape;

    // Array para armazenar o código Brainfuck lido da entrada padrão (stdin)
    char program[65536];

    // Variável do contador de instruções (program counter) e variável auxiliar para loops
    int pc = 0, loop;

    // Lê o código Brainfuck da entrada padrão e armazena no array `program`
    int len = fread(program, 1, sizeof(program), stdin);

    // Garante que o array `program` termina com caractere nulo (string terminada em '\0')
    program[len] = '\0';

    // Loop principal do interpretador, percorre cada caractere do programa Brainfuck
    while (pc < len) {
        switch (program[pc]) {
            // Move o ponteiro da fita para a direita
            case '>': ++ptr; break;

            // Move o ponteiro da fita para a esquerda
            case '<': --ptr; break;

            // Incrementa o valor da célula apontada
            case '+': ++(*ptr); break;

            // Decrementa o valor da célula apontada
            case '-': --(*ptr); break;

            // Imprime o caractere correspondente ao valor da célula atual
            case '.': putchar(*ptr); break;

            // Lê um caractere da entrada padrão e armazena na célula atual
            case ',': *ptr = getchar(); break;

            // Início de um loop: se o valor da célula atual for 0, pula para o final do loop
            case '[':
                if (*ptr == 0) {
                    loop = 1;
                    while (loop > 0) {
                        pc++;
                        if (program[pc] == '[') loop++;
                        else if (program[pc] == ']') loop--;
                    }
                }
                break;

            // Fim de um loop: se o valor da célula atual for diferente de 0, volta para o início do loop
            case ']':
                if (*ptr != 0) {
                    loop = 1;
                    while (loop > 0) {
                        pc--;
                        if (program[pc] == '[') loop--;
                        else if (program[pc] == ']') loop++;
                    }
                }
                break;
        }

        // Avança o contador de instruções para o próximo caractere do programa
        pc++;
    }

    return 0;
}
