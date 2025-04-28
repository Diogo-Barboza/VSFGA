# Ponteiros e alocação dinâmica de memória

## Indireção

- Toda variável é um "apelido" para região da memória
- Cada tipo de dados determina o tamanho da região
    - char: 1B
    - int: 4B
    - long: 8B
    - float: 4B
    - double: 8B

> OBS.: Os tamanhos podem variar de acordo com a estrutura.

| endereçamento | espaço de memória |
|---------------|-------------------|
| 1 | |
| 2 | |
| 3 | |
|4 | |
|5 | |
|6 | | 
|7 | | 
|8 | | 
|9 | |
|10 | |
|11 | | 
|12 | |
|13 | |
|14 | | 
|15 | |
|... | ... | 

Quando declaramos uma variável, ela é **alocada na memória** pelo sistema operacional em tempo de execução. Chamamos de **alocação automática**.
> Ex.: char a; int x

## Definições

- **Alocação**: Reserva espaço de memória para a variável ai entrar no seu escopo.
- **Desalocação**: O modificador <u>static</u> faz que o espaço da variável não seja disponibilizado durante o tempo de execução do problema

Com isso, toda a variável possui um **endereço** que corresponde ao endereço inicial da região de memória e que está alocada.

## Ponteiro

**Ponteiro** é uma classe de variáveis que armazenam **endereços de memória**. 

### Exemplo:

```C
int x = 81;
int *p; // * -> Na declaração indica que a variável é um ponteiro
p = &x; // Operador unário & chama-se operador de endereçamento (endereço de ...)

printf("x = %d\n", *p);
// Lê-se Conteúdo de ...

```

#### O que aconteceu na memória neste exemplo?

1. Alocação automática de X.
2. Armazena 81 em x.
3. Alocação automática de p.

### **IMPORTANTE!**

- O tipo de ponteiro não determina seu tamanho, mas sim qual o tamanho da memória que deve ser manipulada em caso de indireção.
- Um ponteiro costuma ter 8 Bytes, mas varia de acordo com a arquitetura/S.O.


