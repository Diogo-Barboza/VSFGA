# Resumo do Conteúdo do Semestre

## Organização e Estrutura
Um compilador é um sistema complexo dividido em fases que transformam código de alto nível (humano) em baixo nível (máquina).

* **Front-end (Análise):** Focado na linguagem de origem. Verifica se o código está correto.
* **Back-end (Síntese):** Focado na máquina de destino. Otimiza e gera o executável.
* **Middle-end:** Onde ocorrem as otimizações independentes de hardware.

---

## Análise Léxica e Expressões Regulares

A primeira etapa é a leitura dos caracteres. O **Analisador Léxico (Scanner)** agrupa caracteres em unidades chamadas **Tokens**.

* **Expressões Regulares (Regex):** São as regras que definem o que é um token. 
    * *Exemplo:* Uma Regex define que um "Identificador" deve começar com letra e pode conter números.
* **Exemplo Prático:** `soma = 10 + 5;` 
    Vira os tokens: `[ID: soma]`, `[OP: =]`, `[NUM: 10]`, `[OP: +]`, `[NUM: 5]`, `[SYM: ;]`.

---

## Autômatos

Os autômatos são os "motores" por trás da análise. Eles processam os caracteres um a um para validar se a sequência pertence à linguagem.

* **DFA (Autômatos Finitos Determinísticos):** Usados para implementar scanners ultra-rápidos que reconhecem palavras-chave e símbolos sem ambiguidade.

---

## Análise Sintática e Gramáticas

Aqui, o compilador verifica a estrutura da "frase".

* **Gramáticas Livres de Contexto (CFG):** Definem as regras de aninhamento (ex: parênteses, escopo de funções).
* **Parser:** O componente que constrói a árvore de derivação. Se você esquece um `;` ou fecha um parêntese a menos, o erro ocorre aqui.

---

## Estruturas de Dados e Árvore de Sintaxe Abstrata (AST)

O compilador converte o texto plano em uma **AST**. É uma representação em árvore que remove detalhes irrelevantes (como espaços em branco) e foca na lógica.

* **Importância:** Ferramentas como **ESLint**, **Prettier** e **Babel** funcionam manipulando a AST do seu código.



---

## Análise Semântica

Esta fase verifica se o código "faz sentido", além de estar bem escrito.

* **Verificação de Tipos:** "Posso somar uma String com um Inteiro?".
* **Escopo:** "Esta variável que estou usando foi declarada?".
* **Tabela de Símbolos:** Uma estrutura de dados (geralmente Hash Table) que armazena informações sobre todas as variáveis e funções.

---

## Geração de Código e Máquinas Abstratas

O compilador traduz a AST para o código final.

* **Geração de Código:** Transforma a lógica em Assembly ou código de máquina.
* **Máquinas Abstratas (VMs):** Como a JVM ou o Node.js. Elas permitem que o código rode em qualquer CPU através de um **Bytecode**, que é um código intermediário.

---

## Compiladores vs. Interpretadores

Na Engenharia de Software moderna, a linha é tênue:

| Conceito | Descrição | Exemplo |
| :--- | :--- | :--- |
| **Compilador** | Traduz tudo antes da execução (AOT - Ahead of Time). | C, C++, Rust, Go |
| **Interpretador** | Lê e executa linha por linha em tempo real. | Python, PHP (antigo) |
| **JIT (Just-in-Time)** | Compila partes críticas durante a execução para ganhar performance. | JavaScript (V8), Java, C# |
