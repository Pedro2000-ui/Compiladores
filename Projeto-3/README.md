# Compilador e Interpretador Brainfuck com Suporte a UTF-8

Este projeto contém dois programas:

- **`bfc`**: um *compilador* que converte expressões simples do tipo `nome = expressão` para código Brainfuck.
- **`bfe`**: um *interpretador* de Brainfuck que executa o código gerado.

## 🧠 Descrição dos Programas

### `bfc` – Compilador Brainfuck

Esse programa lê uma linha da entrada padrão com o formato:

```
nome = expressão
```

- O `nome` pode conter letras e espaços.
- A `expressão` deve conter **três operandos e dois operadores**, como:
  - `3 + 4 + 1`
  - `5 * 2 - 3`
  - `10 / 2 * 3`

O programa gera um código Brainfuck que:

1. Imprime o nome.
2. Imprime `" = "`.
3. Avalia a expressão e imprime o resultado em decimal.

#### Exemplo:

```bash
echo "credito = 3 + 4 + 1" | ./bfc | ./bfe
```

Saída esperada:

```
credito = 8
```

---

### `bfe` – Interpretador Brainfuck

Esse programa lê o código Brainfuck gerado pelo `bfc` da entrada padrão e executa:

- Memória de 30.000 células.
- Suporte aos comandos padrão do Brainfuck: `+`, `-`, `<`, `>`, `[`, `]`, `.`, `,`.

---

## ⚙️ Funcionamento Interno

### `bfc`

- **Entrada**: string no formato `nome = expressão`.
- **Processamento**:
  - Extrai o nome e a expressão.
  - Avalia a expressão da esquerda para a direita (sem considerar precedência).
  - Gera código Brainfuck que imprime os caracteres do nome, `" = "`, e o resultado da expressão.
- **Saída**: código Brainfuck enviado para o `stdout`.

### `bfe`

- **Entrada**: código Brainfuck (vindo do `bfc` via pipe).
- **Execução**:
  - Interpreta os comandos Brainfuck.
  - Manipula uma fita de memória e imprime os resultados.

---

## ✍️ Sintaxe Suportada

- ✅ Expressões com 3 números e 2 operadores (`+`, `-`, `*`, `/`)
- ✅ Impressão de resultado em decimal
- ⚠️ **Sem suporte a precedência de operadores ou parênteses**

---

## 🧪 Exemplos

```bash
echo "debito = 3 * 5 + 2" | ./bfc | ./bfe
```

Saída:

```
debito = 17
```

```bash
echo "credito = 2 + 2 + 2" | ./bfc | ./bfe
```

Saída:

```
credito = 6
```

---

## 🛠️ Compilação

Compile os dois arquivos com `gcc`:

```bash
gcc -o bfc bfc.c
gcc -o bfe bfe.c
```

---

## 📂 Estrutura do Projeto

```
.
├── bfc.c       # Compilador Brainfuck com suporte a UTF-8
├── bfe.c       # Interpretador Brainfuck
├── README.md   # Instruções e documentação
```

---

## 📌 Observações

- O sistema só aceita expressões com **três operandos e dois operadores**.
- Não há suporte a variáveis nem expressões complexas.
