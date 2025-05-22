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


--- 

## Aplicações de ponteitos

### 1. Alocação dinâmica de memória

```c
int n;
scanf("%d", &n);
int v[n]; // <= ERRADO!!!!!

// JEITO CERTO

int *v;
v = malloc(n * sifeof(int));

printf("%d", v[0]);

free(v); // <= Importante limpar memória pós uso

```
> As funções de manipulação de memória estão na biblioteca stdlib.h.

As "irmãs" de malloc são:

- ``` int *v = calloc(n * sizeof(int)) ```
    - Aloca n blocos de tamanhos sizeof(int) e <u>zera</u> cada bloco.
- ``` v = realloc(v, n * 2 * sizeof(int)) ```
    - Recebe um ponteiro para uma região já alocada e altera seu tamanho, retornando um ponteiro para a nova região.

> Quando uma chamada a alguma das 3 funções falhar, o retorno será zero (ou o processo é encerrado pelo S.O)

> A stdlib.h inclui umas constante chamada NULL que vale **zero**.

```c
int *v = malloc(n * sizeof(int));
if(v == NULL){
    printf("Erro de alocação \n");
    return EXIT_FAILURE;
}
```
### 2. Passagem de Parâmetro

Os parâmetros de funções, em C, são passados por <u>cópia</u> ou <u>valor</u>.

Ex.:
```c
void troca(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 2, y = 5;
    troca(x, y);
    printf("x = %d, y = %d", x, y);

    return 0;
}
```

> A saída sera: x = 2 , y = 5

Para fazer uma passagem por <u>referência</u>, passamos para a função o endereço de memória das variáveis:

Ex.:
```c
void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 2, y = 5;
    troca(x, y);
    printf("x = %d, y = %d", x, y);

    return 0;
}

```

> Agora sim a saída será: x = 5, y = 2.

> obs1.: Já usamos essa construção no Scanf.

> obs2.: Nesse exemplo, os <u>ponteiros</u> são passados por <u>valor</u>.

### 3. Ponteiros e Vetores

Quando declaramos ``` int v[5] ```

- Temos um <u>vetor</u> de 5 posições (indexadas de 0 a 4).
- V é um ponteiro para o endereço incial de um vetor

Deste modo, quando acessamos ``` v[i] = *(v+i) ```, v[i] é ``` *(v + 1 * sizeof(tipo de v))```.

> obs.: v é um ponteiro. v[i] é uma variável, abstração da aritmética de ponteiros. Por isso, que:

> - ``` Scanf("%d", &v[i]); ``` Usa-se &.

> e que:

> - ``` char str[20]; scanf("%s", str); ``` não se usa &.

> e, ainda, 

> - ``` Scanf("%d", (v+i)); ``` Sem & pois v + 1 já é um endereço de memória.

Para matrizes, ``` int M[10][10]; ``` assim, ``` M[i][j] ``` é uma abstração para: ```*(*(m + i) + j) ```.

### 4. Ponteiros para Função

Uma função é um vetor de instruções e seu nome é um ponteiro para o inicio desse vetor.




