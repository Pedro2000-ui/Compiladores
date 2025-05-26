# 🛠️ Fundamentos de Compiladores

Este repositório contém anotações, materiais e projetos desenvolvidos para estudar e implementar os principais conceitos de **compiladores** — indo desde a análise léxica até a geração de código final.

## 📘 O que é um compilador?

Um **compilador** é um programa que traduz um código escrito em uma linguagem de programação (linguagem-fonte) para outra linguagem, geralmente uma linguagem de máquina ou intermediária que pode ser executada por um computador.

Esse processo acontece em diversas etapas:

### ⚙️ Etapas de um Compilador

1. **Análise Léxica (Scanner)**  
   Quebra o código-fonte em **tokens** (palavras-chave, identificadores, números, símbolos, etc.).

2. **Análise Sintática (Parser)**  
   Organiza os tokens em uma **estrutura hierárquica** (árvore sintática) seguindo regras gramaticais da linguagem.

3. **Análise Semântica**  
   Verifica **significados** e restrições — tipos, escopos, uso correto de variáveis e funções.

4. **Geração de Código Intermediário**  
   Traduz a árvore para uma linguagem intermediária, mais próxima da máquina.

5. **Otimização de Código**  
   Melhora o desempenho e reduz redundâncias do código intermediário.

6. **Geração de Código Final**  
   Gera o código de máquina (binário, assembly) executável pela arquitetura alvo.

7. **Ligação e Execução**  
   Combina os módulos compilados e bibliotecas, gerando o programa final.

---

## 📁 Projetos

Abaixo estão os projetos práticos desenvolvidos como parte dos estudos de compiladores. Clique em cada um para ir direto ao repositório ou pasta com o código e documentação:

| Projeto | Descrição |
|--------|-----------|
| [Compilador Neander](./Projeto-1/README.md) | Aplicação prática dos conceitos de funcionamento de um compilador em C e execução em uma máquina virtual Neander |
| [FielLang - Compilador de linguagem temática](./Projeto-2/README.md) | Uma linguagem inspirada no Corinthians, com gramática personalizada e compilador próprio. |
| [Compilador e Interpretador Brainfuck](./Projeto-3/README.md) | O projeto consiste em um compilador (bfc) e um interpretador (bfe) para a linguagem Brainfuck. O compilador (bfc) recebe uma entrada no formato nome = expressão (como débito = 3 * 5 + 2), converte essa entrada em código Brainfuck que imprime o nome e o resultado da expressão. O interpretador (bfe) executa esse código Brainfuck, exibindo na tela o nome e o resultado (por exemplo, débito = 17). |

> ⚠️ Certifique-se de navegar até cada pasta para ver os arquivos-fonte, instruções de execução e exemplos de código.
