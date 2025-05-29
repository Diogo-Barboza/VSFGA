# Estruturas Lineares: Lista, fila e pilha

## Listas encadeadas

Numas lista encadeada, cada elemento aponta para o próximo, sem que estejam em posiçoes sequenciais na memória.

### 1. Listas encadeadas simples

![Lista Ecadeada Simples](../../../images/listaEncadeada.png)

Cada elemento aponta apenas para o que vem a seguir. Cada caixinha é chamada de nó ou célula e é implementada da seguinte forma:

```c
type def struct celula{
    int dado;
    struct celula *prox;
} celula;
```

Implementaremos listas simplesmente encadeadas com nó cabeça;

#### Criação da lista

```c
celula *cria_lista(){
    celula *le = malloc(sizeof(celula));
    le -> prox = NULL;
    return le;
}
```

> (*le).dado = 10, é a mesma coisa que le -> dado = 10

#### Busca

```c
celula *busca(celula *le, int x){
    for(celula *prog; ptr != NULL; ptr = ptr -> prox)
        if(ptr -> dado == x) return ptr;
        return NULL;
}
```

#### Inserção 

```c
void insere(celula *ptr, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = ptr -> prox;
    ptr -> prox = novo;
} // COMPLEXIDADE: O(1)
```

Para inserir no começo, basta chamar <u>insere</u> com le. Para inserir depois de um elemento y da lista, basta chamar busca e com seu retorno, chamar insere.

#### Remoção

```c
int remove(celula *ptr){
    celula *lixo = ptr -> prox;
    int x = lixo -> dado;
    ptr -> prox = lixo -> prox;
    free(ptr);
    return x;
}
```

> Para remover o primeiro elemento da lista, chama-se remove com le.

Agora para exercitar, pense: 

- Como remover um elemento y?
- Como remover o último elemento da lista?

#### Destroi lista

```c
void destroi_lista(celula *le){
    while(le -> prox != NULL)
        remove(le);
    free(le);
} // COMPLEXIDADE: O(n)
```

