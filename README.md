# Compiladores
Aplicação dos conceitos de funcionamento de um compilador em C.

# Executor/Neander
O executor é um simulador da máquina virtual Neander, um modelo de computador hipotético usado para fins educacionais. O simulador é capaz de carregar e executar programas binários escritos para a arquitetura Neander.

## Visão Geral
O Neander é uma máquina de 8 bits com um conjunto de instruções simples. Este simulador implementa a arquitetura Neander, permitindo a execução de programas escritos em linguagem de máquina.

### Componentes Principais
- Memória (mem): Um array de 256 posições, onde cada posição armazena um valor de 8 bits.
- Acumulador (AC): Registrador usado para armazenar resultados de operações aritméticas e lógicas.
- Contador de Programa (PC): Registrador que aponta para a próxima instrução a ser executada.
- Flags (N e Z): Flags que indicam se o resultado da última operação foi negativo (N) ou zero (Z).

### Instruções Suportadas
- NOP: Não faz nada.
- STA: Armazena o valor do AC na memória.
- LDA: Carrega um valor da memória no AC.
- ADD: Soma um valor da memória ao AC.
- OR: Operação lógica OR.
- AND: Operação lógica AND.
- NOT: Inverte os bits do AC.
- JMP: Salta para um endereço de memória.
- JN: Salta se a flag N estiver ativa.
- JZ: Salta se a flag Z estiver ativa.
- HLT: Para a execução do programa.

### Estrutura do Código
O código está organizado em três arquivos principais:
- main.c: Contém a função main, que é o ponto de entrada do programa. Ele lida com a leitura do arquivo binário e inicia a execução do programa.
- neander.c: Contém a implementação das funções que simulam as instruções da máquina Neander.
- neander.h: Contém as declarações das funções e variáveis globais usadas no simulador.

#### Funções Principais
- processarArquivo(FILE *input): Lê o arquivo binário e carrega o programa na memória.
- exec_instruction(uint16_t instrucao): Executa uma instrução com base no código fornecido.
- flag_update(): Atualiza as flags N e Z com base no valor atual do AC.
- print_estado_final(): Imprime o estado final do acumulador, contador de programa e memória.

### Como Funciona
- Carregamento do Programa: O simulador lê um arquivo binário que contém o programa a ser executado. O arquivo começa com um cabeçalho específico (0x03 0x4E 0x44 0x52), seguido pelos dados que são carregados na memória.
- Execução das Instruções: O simulador executa as instruções uma a uma, atualizando o AC, PC e flags conforme necessário.
- Finalização: Quando a instrução HLT é encontrada, o simulador para a execução e imprime o estado final da máquina.

## Estrutura do Projeto
O projeto está organizado da seguinte forma:
```
compiladores/
├── arquivos_binarios/ # Pasta contendo arquivos binários para execução
│ └── soma.mem # Exemplo de programa binário
├── neander/ # Pasta contendo o código fonte do simulador
│ ├── neander.c # Implementação das funções do simulador
│ └── neander.h # Cabeçalho com declarações de funções e variáveis
├── main.c # Arquivo principal com a função main
```

### Requisitos
- Compilador GCC instalado.
- Um arquivo binário no formato correto (cabeçalho 0x03 0x4E 0x44 0x52).

## Como Compilar e Executar
### Clone o Repositório
Primeiro, clone o repositório para o seu ambiente local:

```
git clone https://github.com/seu-usuario/compiladores.git
cd compiladores
```

### Compile o Projeto

```
gcc main.c neander/neander.c -o neander
```
Isso gerará um executável chamado neander

### Execute o Simulador

```
./neander.exe arquivos_binarios/soma.mem
```

### Verifique a Saída
O simulador exibirá o estado final do acumulador, contador de programa e memória. A saída será algo assim:

```
Acumulador: 8
Program Counter: 6
Estado da Memória:
mem[000] = 0 (0x00)
...
mem[010] = 5 (0x05)
mem[011] = 3 (0x03)
mem[012] = 8 (0x08)
...
```
