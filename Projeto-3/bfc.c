#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

// Função que imprime em Brainfuck um caractere UTF-8 (de até 4 bytes)
// c: array de bytes do caractere UTF-8
// len: número de bytes (1 a 4)
void print_utf8_char(unsigned char *c, int len) {
    for (int i = 0; i < len; i++) {
        printf("[-]");                    // zera célula atual
        for (int j = 0; j < c[i]; j++)    // incrementa até valor do byte
            printf("+");
        printf(".");                      // imprime o byte
        if (i < len - 1) printf(">");     // move para a próxima célula se ainda for o mesmo caractere
    }
    printf(">");                          // move para a próxima célula para o próximo caractere
}

// Função que imprime uma string UTF-8 inteira em Brainfuck
void print_utf8_string(const char *s) {
    unsigned char c;
    while (*s) {
        c = (unsigned char)*s;
        int len = 1;

        // Detecta quantos bytes tem o caractere UTF-8
        if ((c & 0xF8) == 0xF0) len = 4;
        else if ((c & 0xF0) == 0xE0) len = 3;
        else if ((c & 0xE0) == 0xC0) len = 2;

        print_utf8_char((unsigned char *)s, len);
        s += len; // avança para o próximo caractere UTF-8
    }
}

// Imprime um número decimal como string em Brainfuck
void print_number(int n) {
    char str[12];
    sprintf(str, "%d", n);  // converte número para string
    for (int i = 0; i < strlen(str); i++) {
        printf("[-]");                       // zera célula atual
        for (int j = 0; j < str[i]; j++)     // incrementa até código ASCII do caractere numérico
            printf("+");
        printf(".>");                        // imprime e move para próxima célula
    }
}

// Função que avalia uma expressão simples do tipo: número operador número operador número
int avaliar_expressao(const char *expr) {
    int a, b, c;
    char op1, op2;

    // Lê do tipo "3 * 5 + 2"
    sscanf(expr, "%d %c %d %c %d", &a, &op1, &b, &op2, &c);

    int r1 = 0;
    // Aplica primeira operação
    switch (op1) {
        case '+': r1 = a + b; break;
        case '-': r1 = a - b; break;
        case '*': r1 = a * b; break;
        case '/': r1 = a / b; break;
    }

    int resultado = 0;
    // Aplica segunda operação
    switch (op2) {
        case '+': resultado = r1 + c; break;
        case '-': resultado = r1 - c; break;
        case '*': resultado = r1 * c; break;
        case '/': resultado = r1 / c; break;
    }

    return resultado;
}

int main() {
    setlocale(LC_ALL, ""); // Ativa suporte a UTF-8 com base no locale do sistema

    char linha[256];
    // Lê uma linha da entrada padrão
    if (!fgets(linha, sizeof(linha), stdin)) return 1;

    // Procura o sinal de igual "="
    char *igual = strchr(linha, '=');
    if (!igual) return 1; // Erro se não tiver "="

    *igual = '\0';              // Separa a string em duas partes
    char *nome = linha;         // Parte antes do '=' é o "nome"
    char *expressao = igual + 1; // Parte depois do '=' é a expressão matemática

    // Limpa espaços no início e fim de `nome`
    while (*nome == ' ') nome++;
    char *end = nome + strlen(nome) - 1;
    while (*end == ' ' && end > nome) *end-- = '\0';

    // Limpa espaços no início e fim da `expressao`
    while (*expressao == ' ') expressao++;
    char *end2 = expressao + strlen(expressao) - 1;
    while (*end2 == ' ' && end2 > expressao) *end2-- = '\0';

    // Zera células iniciais antes de imprimir, por segurança
    printf("[-]>>>[-]<<<\n");

    // Imprime o nome da variável e o " = " em Brainfuck
    print_utf8_string(nome);
    print_utf8_string(" = ");

    // Avalia a expressão numérica
    int resultado = avaliar_expressao(expressao);

    // Imprime o número resultante
    print_number(resultado);

    return 0;
}
