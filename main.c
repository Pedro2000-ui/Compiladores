#include <stdio.h>
#include <stdint.h>
#include "assembler/assembler.h"
#include "neander/neander.h"

int main(void) {
    
    // Abre o arquivo .txt com instruções em Assembler e converte pra binário
    FILE *inputAssembler = fopen("./arquivos_assembler/entrada.txt", "r");

    // Salva a saída da conversão do assembler pra binário em um arquivo .mem
    FILE *outputAssembler = fopen("./arquivos_binarios/saida.mem", "wb");
  
    converter_binario(inputAssembler, outputAssembler);

    // Abre o arquivo binário gerado pelo conversor assembler e o processa
    FILE *inputNeander = fopen("./arquivos_binarios/saida.mem", "rb");
    if (inputNeander == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }

    // Processa o arquivo
    int result = processarArquivo(inputNeander);
    fclose(inputNeander);

    if (result == -1) {
        printf("Arquivo inválido.\n");
    }

    return 0;
}