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

##### Busca Iterativa

```c
celula *busca(celula *le, int x){
    for(celula *ptr = le; ptr != NULL; ptr = ptr -> prox)
        if(ptr -> dado == x) return ptr;
    return NULL;
}
```

Fazendo alguns exercícios do MOJ, surgiu uma questão de implementar uma função de busca de forma recursiva. Dessa forma:

##### Busca Recursiva

```c
celula *busca_rec(celula *le, int x){
    if (le == NULL) return NULL;
    if ( le -> prox == x) return le;

    return busca_rec(le->prox, x);
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
    celula *proxNo = lixo -> prox;
    int x = lixo -> dado;
    ptr -> prox = proxNo;
    
    free(lixo);
    return x;
}
```

> Para remover o primeiro elemento da lista, chama-se remove com le.

Agora para exercitar, pense: 

- Como remover um elemento y?

    - Estive estudando, e o princípio é. Temos que saber a celula anterior a que queremos saber, e fazer essa anterior apontar para a que ela aponta. Dessa forma:

    ```c
    int removeItem(celula *le, int x){
        for ( celula *atual = le; atual != NULL; atual = atual -> prox){
            if ( atual -> prox -> dado == x){
                celula *to_remove = atual -> prox;

                atual -> prox = to_remove -> prox;

                free(to_remove);

                return 1;
            }
        }
        return 0; // 0 se n econtrou
    }
    ```

- Como remover o último elemento da lista?
    - Podemos seguir do mesmo jeito, achamos o último elemento que aponta para NULL, pegamos o antecessor e apontamos para NULL;
    ```c
    int removeUltimo(celula *le){
        if(le -> prox == NULL) return 0; 

        for (celula *atual = le; atual != NULL; atual = atual -> prox){
            if ( atual -> prox -> prox == NULL) {
                free(atual->prox);
                atual -> prox = NULL;
                return 1;
            }
        }
        return 0;
    }
    ```



#### Destroi lista

```c
void destroi_lista(celula *le){
    while(le -> prox != NULL)
        remove(le);
    free(le);
} // COMPLEXIDADE: O(n)
```



