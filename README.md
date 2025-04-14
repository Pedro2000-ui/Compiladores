# Compiladores

Este projeto é uma aplicação prática dos conceitos de funcionamento de um compilador em C, abrangendo as etapas de análise léxica, sintática, geração de código assembly e execução em uma máquina virtual Neander.

## 📚 Gramática Aceita

O compilador atualmente aceita expressões aritméticas simples de soma e subtração, seguindo a gramática:
```
<expr> ::= <num> (<space>? ("+" | "-") <space>? <num>)+
<num> ::= [0-9]+
<space> ::= " "
```

### Exemplos válidos:

- `3 + 5`
- `10 + 20 - 30`

### Exemplos inválidos:

- `+ 5 5` (operador no início)
- `3 3 +` (números consecutivos sem operador)

## 🔄 Etapas do Compilador

1. **Lexer (Analisador Léxico):**
   - Verifica se a entrada está dentro da gramática definida.
   - Tokeniza a expressão, identificando números (`NUM`) e operadores (`OPR`).
   - Gera um arquivo com os tokens para o parser.

2. **Parser (Analisador Sintático):**
   - Lê os tokens gerados pelo lexer.
   - Verifica se há erros léxicos indicados pelo lexer (`ERR`).
   - Valida a estrutura da expressão (por exemplo, impede que expressões como `+ 5 5` sejam consideradas válidas).
   - Se a expressão for válida, gera o código assembly correspondente.

3. **Assembler:**
   - Converte o código assembly gerado pelo parser em código binário.
   - Prepara o código binário para execução na máquina virtual Neander.

4. **Neander (Máquina Virtual):**
   - Executa o código binário gerado pelo assembler.
   - Simula a execução da expressão aritmética, realizando as somas conforme definido.

## 🚀 Como Compilar e Executar

### Pré-requisitos

- Sistema operacional Windows ou Linux.
- [MinGW](https://www.mingw-w64.org/) instalado e configurado no PATH para utilização do `gcc`.

### Passos

1. Clone este repositório:
    ```bash
    git clone https://github.com/Pedro2000-ui/Compiladores.git
   
2. Navegue até o diretório do projeto:
    ```bash
    cd Compiladores

#### 🪟 **No Windows**
1. Execute o arquivo `build.run.bat` com um duplo clique
    - Este script irá compilar todos os módulos (`lexer`, `parser`, `assembler`, `neander`) e executar o programa.
    - A saída será exibida no terminal, incluindo o resultado da execução da expressão.


#### 🐧 **No Linux**
1. Compile manualmente os arquivos fonte com `gcc`:
    ```bash
    gcc lexer.c -o lexer
    gcc parser.c -o parser
    gcc assembler.c -o assembler
    gcc neander.c -o neander
2. Execute os módulos na ordem correta:
    ```bash
    ./lexer < input.txt > tokens.txt
    ./parser < tokens.txt > assembler.txt
    ./assembler < assembler.txt > binario.txt
    ./neander < binario.txt
3. O resultado da execução será exibido no terminal


## 🗂️ Estrutura do Projeto
    Compiladores/
    ├── lexer/           # Contém o analisador léxico
    ├── parser/          # Contém o analisador sintático
    ├── assembler/       # Contém o montador que gera o código binário
    ├── neander/         # Contém a máquina virtual Neander
    ├── main.c           # Arquivo principal que integra todos os módulos
    ├── build_run.bat    # Script para compilar e executar o projeto no Windows
    └── README.md        # Este arquivo

### 📄 Exemplo de Uso
Dada a expressão:
  ``` 
    3 + 5 + 2
  ```

A saída esperada após a execução será:
  ```
    ; Programa gerado automaticamente para somar números
    DADO 3 ; inicializa o end 0 com o valor 3
    DADO 5 ; inicializa o end 1 com o valor 5
    DADO 2 ; inicializa o end 2 com o valor 2
    LDA 0 ; Carrega o valor do endereço 0 no acumulador
    ADD 1 ; Soma o valor do endereço 1 ao acumulador
    ADD 2 ; Soma o valor do endereço 2 ao acumulador
    STA 255 ; Armazena o resultado no endereço 255
    HLT ; Para a execução
  ```
E o resultado da execução na máquina virtual Neander será:
  ```
    Acumulador: 10
    Program Counter: 11
    Estado da Memória:
    mem[000] = 3 (0x03)
    mem[001] = 5 (0x05)
    mem[002] = 2 (0x02)
    mem[255] = 10 (0x0A)
    ...
  ```

# 🧠 Observações
  - O lexer permite expressões que estejam dentro da gramática definida, mas o parser é responsável por validar a estrutura correta da expressão.
  - O projeto é uma ferramenta educacional para demonstrar o funcionamento de um compilador simples, desde a análise léxica até a execução em uma máquina virtual.
