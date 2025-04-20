#ifndef NEANDER_H
#define NEANDER_H

#include <stdio.h>
#include <stdint.h>

// Declaração das funções do simulador Neander
int processarArquivo(FILE *input); // Processa o arquivo binário e executa o programa
void print_estado_final();         // Imprime o estado final (AC, PC e memória)
void NOP();                        // Instrução NOP (No Operation)
void STA(uint16_t mem_addr_idx);   // Instrução STA (Store Accumulator)
void LDA(uint16_t mem_addr_idx);   // Instrução LDA (Load Accumulator)
void ADD(uint16_t mem_addr_idx);   // Instrução ADD (Add to Accumulator)
void OR(uint16_t mem_addr_idx);    // Instrução OR (Logical OR)
void AND(uint16_t mem_addr_idx);   // Instrução AND (Logical AND)
void NOT();                        // Instrução NOT (Logical NOT)
void JMP(uint16_t mem_addr_idx);   // Instrução JMP (Jump)
void JN(uint16_t mem_addr_idx);    // Instrução JN (Jump if Negative)
void JZ(uint16_t mem_addr_idx);    // Instrução JZ (Jump if Zero)
void flag_update();                // Atualiza as flags N (Negative) e Z (Zero)

// Variáveis globais
extern uint16_t mem[256]; // Memória do Neander (256 posições)
extern int ac;            // Accumulator (Registrador Acumulador)
extern int pc;            // Program Counter (Contador de Programa)
extern int n;             // Flag Negative
extern int z;             // Flag Zero

#endif // NEANDER_H