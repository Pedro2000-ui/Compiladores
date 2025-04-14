#include <stdio.h>
#include <stdint.h>
#include "neander.h"

// Definição das variáveis globais
uint16_t mem[256]; // Memória do Neander (256 posições)
int ac = 0;        // Accumulator (Registrador Acumulador)
int pc = 0;        // Program Counter (Contador de Programa)
int n = 0;         // Flag Negative
int z = 0;         // Flag Zero

// IDs das instruções (mnemônicos)
uint16_t mneumonic_id[] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x80, 0x90, 0xa0, 0xf0};

// Função para imprimir o estado final (AC, PC e memória)
void print_estado_final()
{
    printf("Acumulador: %d\n", (int8_t)ac); // Imprime o valor do acumulador
    printf("Program Counter: %d\n", pc); // Imprime o valor do contador de programa
    printf("Estado da Memória:\n");
    for (int i = 0; i < 256; i++)
    {
        
        printf("mem[%03d] = %d (0x%02x)\n", i, (int8_t)mem[i], mem[i]); // Imprime cada posição da memória
    }
}

// Função para executar uma instrução
int exec_instruction(uint16_t instrucao)
{
    printf("Executando instrução: 0x%x\n", instrucao); // Log da instrução sendo executada
    switch (instrucao)
    {
    case 0x00:
        NOP();
        break; // Instrução NOP
    case 0x10:
        STA(mem[pc + 1]);
        break; // Instrução STA
    case 0x20:
        LDA(mem[pc + 1]);
        break; // Instrução LDA
    case 0x30:
        ADD(mem[pc + 1]);
        break; // Instrução ADD
    case 0x40:
        OR(mem[pc + 1]);
        break; // Instrução OR
    case 0x50:
        AND(mem[pc + 1]);
        break; // Instrução AND
    case 0x60:
        NOT();
        break; // Instrução NOT
    case 0x80:
        JMP(mem[pc + 1]);
        break; // Instrução JMP
    case 0x90:
        JN(mem[pc + 1]);
        break; // Instrução JN
    case 0xa0:
        JZ(mem[pc + 1]);
        break; // Instrução JZ
    case 0xf0:
        print_estado_final();
        return 1; // Instrução HLT
    }
    return 0;
}

// Função para processar o arquivo binário
int processarArquivo(FILE *input)
{
    uint8_t header[4];
    fread(header, sizeof(header), 1, input); // Lê o cabeçalho do arquivo

    // Verifica se o cabeçalho é válido
    if (header[0] != 0x03 || header[1] != 0x4e || header[2] != 0x44 || header[3] != 0x52)
    {
        return -1; // Retorna erro se o cabeçalho for inválido
    }

    fread(mem, sizeof(mem), 1, input); // Carrega o programa na memória
    while (1)
    {
        int exec_op = 0;
        for (int i = 0; i < 11; i++)
        {
            if (mem[pc] == mneumonic_id[i]) // Verifica se a instrução é válida
            {                                            
                int finished = exec_instruction(mem[pc]); // Executa a instrução
                exec_op = 1;
                if (finished)
                {
                    return 0; // Encerra a execução se a instrução for HLT
                }
                break;
            }
        }
        if (!exec_op)
        {
            pc++; // Avança para a próxima instrução
        }
    }
    return 0;
}

// Função para atualizar as flags N e Z
void flag_update()
{
    n = (ac < 0) ? 1 : 0;  // Atualiza a flag Negative
    z = (ac == 0) ? 1 : 0; // Atualiza a flag Zero
}

// Implementação das instruções
void NOP() { pc++; } // NOP: Incrementa o PC

void STA(uint16_t mem_addr_idx)
{
    mem[mem_addr_idx] = ac;
    flag_update();
    pc += 2;
} // STA: Armazena o AC na memória

void LDA(uint16_t mem_addr_idx)
{
    ac = mem[mem_addr_idx];
    flag_update();
    pc += 2;
} // LDA: Carrega o valor da memória no AC

void ADD(uint16_t mem_addr_idx)
{
    ac += mem[mem_addr_idx];
    flag_update();
    pc += 2;
} // ADD: Soma o valor da memória ao AC

void OR(uint16_t mem_addr_idx)
{
    ac = ac | mem[mem_addr_idx];
    flag_update();
    pc += 2;
} // OR: Operação lógica OR

void AND(uint16_t mem_addr_idx)
{
    ac = ac & mem[mem_addr_idx];
    flag_update();
    pc += 2;
} // AND: Operação lógica AND

void NOT()
{
    ac = ~ac;
    flag_update();
    pc++;
} // NOT: Inverte os bits do AC

void JMP(uint16_t mem_addr_idx) { pc = mem_addr_idx; } // JMP: Salta para o endereço especificado

void JN(uint16_t mem_addr_idx)
{
    if (n == 1)
        pc = mem_addr_idx;
    else
        pc += 2;
} // JN: Salta se a flag N estiver ativa

void JZ(uint16_t mem_addr_idx)
{
    if (z == 1)
        pc = mem_addr_idx;
    else
        pc += 2;
} // JZ: Salta se a flag Z estiver ativa