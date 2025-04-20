# 🧥 FielLang

**FielLang** é uma linguagem de programação fictícia criada em homenagem ao Corinthians, refletindo a paixão, garra e identidade do "bando de loucos". Sua sintaxe é personalizada com termos temáticos, como `Vai corinthians`, `entregaTotal`, `seTemRaca`, entre outros.

A linguagem é baseada em conceitos comuns de linguagens imperativas, com suporte para **declarações de variáveis**, **funções**, **procedimentos**, **atribuições**, **chamadas** e **estruturas condicionais**.

## 🎯 Objetivo

Demonstrar os fundamentos da construção de linguagens formais e gramáticas, aplicando conceitos de compiladores com uma pitada de irreverência corinthiana.

---

## ✍ Gramática BNF

```plaintext

<programa>             ::= <inicio> <quebra_linha>+ <corpo_programa> <quebra_linha>+ <fim>

<inicio>               ::= "Vai corinthians"
<fim>                  ::= "O campeao dos campeoes"
<quebra_linha>         ::= "\n"

<corpo_programa>       ::= (<declaracao> | <comando>) (<quebra_linha>+ (<declaracao> | <comando>))*

<declaracao>           ::= <declaracao_variavel> | <declaracao_funcao> | <declaracao_procedimento>

<declaracao_variavel>  ::= <tipo> <espaco> (<identificador> | <atribuicao>)

<tipo>                 ::= "camisa" | "raca" | "grito" | "ingresso"

<identificador>        ::= <letra> (<letra> | <numero>)*
<letra>                ::= [A-Z] | [a-z]
<numero>               ::= [0-9]

<atribuicao>           ::= <identificador> <espaco>? "=" <espaco>? (<valor> | <expressao>)

<valor>                ::= <booleano> | <string_literal> | <numero_literal>
<booleano>             ::= "true" | "false"
<string_literal>       ::= <aspas> <string> <aspas>
<aspas>                ::= "\""
<string>               ::= (<letra> | <numero> | <espaco>)*
<numero_literal>       ::= <inteiro> | <float>
<inteiro>              ::= <numero>+
<float>                ::= <numero>+ "." <numero>+

<expressao>            ::= <expressao_logica>

<expressao_logica>     ::= <expressao_relacional> (<espaco>? <operador_logico> <espaco>? <expressao_relacional>)*

<expressao_relacional> ::= <expressao_aritmetica> (<espaco>? <operador_relacional> <espaco>? <expressao_aritmetica>)?

<expressao_aritmetica> ::= <termo> (<espaco>? <operador_add_sub> <espaco>? <termo>)*
<termo>                ::= <fator> (<espaco>? <operador_multi_div> <espaco>? <fator>)*
<fator>                ::= <numero_literal> | <booleano> | <string_literal> | <identificador> | <chamada_funcao> | "(" <espaco>? <expressao> <espaco>? ")"

<operador_add_sub>     ::= "+" | "-"
<operador_multi_div>   ::= "*" | "/"
<operador_relacional>  ::= "==" | "!=" | ">" | "<" | ">=" | "<="
<operador_logico>      ::= "AND" | "OR"

<espaco>               ::= " "

<declaracao_funcao>       ::= "jogadaEnsaiada" <espaco> <tipo> <espaco> <identificador> "(" <espaco>? <parametros_opcional>* <espaco>? ")" <espaco> <bloco_com_retorno>
<declaracao_procedimento> ::= "entregaTotal" <espaco> <identificador> "(" <espaco>? <parametros_opcional>* <espaco>? ")" <espaco> <bloco_sem_retorno>

<parametros_opcional>  ::= <parametros>
<parametros>           ::= <parametro> <mais_parametros>*
<mais_parametros>      ::= "," <espaco>? <parametros>
<parametro>            ::= <tipo> <espaco> <identificador>

<bloco_com_retorno>    ::= "{" <quebra_linha>+ <bloco_conteudo> <quebra_linha>+ "retorna" <espaco> <identificador> <quebra_linha>+ "}"
<bloco_sem_retorno>    ::= "{" <quebra_linha>+ <bloco_conteudo> <quebra_linha>+ "}"

<bloco_conteudo>       ::= (<comando> | <declaracao_variavel>) (<quebra_linha>+ (<comando> | <declaracao_variavel>))*

<comando>              ::= <atribuicao> 
                       | <chamada_funcao> 
                       | <chamada_procedimento> 
                       | <condicional>

<condicional>          ::= <se> <se_senao>* <senao>?

<se>                   ::= "seTemRaca" "(" <espaco>? <expressao> <espaco>? ")" <espaco>? <bloco_sem_retorno>
<se_senao>             ::= <quebra_linha>* "seNaoDesistiu" "(" <espaco>? <expressao> <espaco>? ")" <espaco>? <bloco_sem_retorno>
<senao>                ::= <quebra_linha>* "seNaoTemCoracao" <espaco>? <bloco_sem_retorno>

<chamada_funcao>       ::= <identificador> "(" <espaco>? <argumentos_opcional>? <espaco>? ")"
<chamada_procedimento> ::= <identificador> "(" <espaco>? <argumentos_opcional>? <espaco>? ")"

<argumentos_opcional>  ::= <argumentos>
<argumentos>           ::= <expressao> <mais_argumentos>*
<mais_argumentos>      ::= "," <espaco>? <argumentos>

```

## 📀 Estrutura Geral do Programa

Um programa válido em FielLang segue a seguinte estrutura:

```plaintext
Vai corinthians
<corpo do programa>
O campeao dos campeoes
```

---

## 🧱 Componentes da Linguagem

### ✅ Tipos

FielLang suporta quatro tipos primitivos:

| Tipo FielLang | Descrição      |
|---------------|----------------|
| `camisa`      | Número inteiro |
| `raca`        | Booleano       |
| `grito`       | String         |
| `ingresso`    | Número float   |

### 📦 Declarações de Variáveis

```plaintext
camisa numero
grito nome = "Corinthians"
ingresso preco = 15.99
```

### 🧮 Expressões

Permite:

- Aritméticas: `+`, `-`, `*`, `/`
- Relacionais: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Lógicas: `AND`, `OR`

```plaintext
raca verdadeiro = true
camisa total = preco + 10
seTemRaca(a == 10) {
    a = b + c
}

```

---

## 🧠 Funções e Procedimentos

### 🔁 Funções (`jogadaEnsaiada`)

Declara uma função com retorno.

```plaintext
jogadaEnsaiada camisa soma(camisa a, camisa b) {
  resultado = a + b
  retorna resultado
}
```

### ⚙️ Procedimentos (`entregaTotal`)

Procedimentos não retornam valores.

```plaintext
entregaTotal mostrar(grito msg) {
  exibir(msg)
}
```

---

## 🚨 Chamada de Função / Procedimento

```plaintext
soma(10, 5)
mostrar("Vai, Corinthians!")
```

---

## 🔀 Condicionais

### 🥄 `seTemRaca` (if)
### 🏃 `seNaoDesistiu` (else if)
### 💔 `seNaoTemCoracao` (else)

```plaintext
seTemRaca(condicao) {
  // bloco executado se verdadeiro
}
seNaoDesistiu(outraCondicao) {
  // outro bloco
}
seNaoTemCoracao {
  // bloco final
}
```

---

## 📌 Regras Importantes

- Todo programa deve começar com `Vai corinthians` e terminar com `O campeao dos campeoes`.
- Quebras de linha são obrigatórias entre comandos.
- Nomes de variáveis seguem o padrão: começam com letra e podem conter letras ou números.
- Strings devem estar entre aspas (`"`).

---

## 💡 Exemplo Completo

```plaintext
Vai corinthians

camisa gols = 3
raca temFé = true

jogadaEnsaiada camisa dobro(camisa valor) {
  resultado = valor * 2
  retorna resultado
}

entregaTotal mostraMensagem(grito msg) {
  exibir(msg)
}

seTemRaca(temFé) {
  mostraMensagem("Vai, Corinthians!")
}
seNaoDesistiu(gols > 0) {
  mostraMensagem("Ainda dá!")
}
seNaoTemCoracao {
  mostraMensagem("É só mais um jogo.")
}

O campeao dos campeoes
```

---

## 🚧 Funcionalidades Futuras

- Estruturas de repetição
- Incluir expressão aritmética mod

---
