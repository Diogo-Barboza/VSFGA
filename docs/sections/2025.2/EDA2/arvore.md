# Árvore

Uma árvore é um conjunto de <u>nós</u> interligados de tal forma que existe apenas um único caminho ente quaisqier dois nós da árvore. Toda árvore é dotada de <u>estrutura topológia</u>: Raiz, e rodem dos filhos.

- Todo nó sem filhos é chamado de folha. Dizemos que a **altura** de um nó é o tamanho de um caminho (qtde de arestas) à folha descendente mais distante.
- Dizemos que a **profundidade** de um nó é a distância (tamanho do caminho) à raiz da árvore.
- Dizemos que uma árvore cujos nós possuem no máximo dois filhos é uma árvore binária.

## Definição recursiva

![árvore rec](../../../images/arvorerec.png)

## Percursão numa AB (Árvore Binária)

1. Percursão em profundidade
    - Pré-ordem
    - Em ordem
    - Pós-ordem

## Percurso em Profundidade

![alt text](../../../images/arvoreexemplo.png)

### Implementação

Tipo abstrado de dados (TAD)

![TAD](../../../images/listarvore.png)

Código em C, mas a estrutura é assim em outras linguagens tambem.

```c
typedef struct celula {
    int dado;
    struct celula *esq, *dir;
}celula;

celula *cria_arvore(int x){
    celula *raiz = malloc(sizeof(celula));
    raiz -> esq = NULL;
    raiz -> dir = NULL;
    raiz -> dado = x;

    return raiz;
}

celula *preOrdem(celula *raiz){
    if(raiz != NULL){
        printf("%d ", raiz -> dado);
        preOrdem(raiz-> esq);
        preOrdem(raiz-> dir);
    }
}

celula *preOrdemInte(celula *raiz){ // De forma iterativa
    pilha *p = cria_pilha();
    empilha(p, raiz);
    while(!pilha_vazia(p)){
        raiz = desempilha(p);
        if(raiz -> dir != NULL) empilha(p, raiz -> dado);
        if(raiz -> esq != NULL) empilha(p, raiz -> dado);
        printf("%d ", raiz -> dado);
    }
}
```

Como encontrar a altura de uma árvore?

```c
int altura (celula *raiz){
    if (raiz != NULL){
        int he = altura(raiz -> esq);
        int hd = altura(raiz -> dir);

        if(he > hd) return he + 1;
        else return hd + 1;
    }
    else return 1;
}
```

## Árvore Binária de Busca (ABB)

Uma ABB é uma árvore binária tal que, para todo nó x: $e \leq x \leq d$. Para qualquer e pertencente à subárvore esquerda de x e qualquer pertence a subárvore diretira de x.

### Busca Árvore Binaria

```c
celula *busca(celula *raiz, int x){
    if(raiz != NULL){
        if(raiz -> dado > x){
            return busca(raiz -> esq, x);
        }else if (raiz -> dado < x){
            return busca(raiz -> dir, x);
        }
    }
    return raiz;
}

celula *buscaInt(celula *raiz, int x){ // de forma interativa
    while(raiz != NULL && raiz -> dado != x){
        if(x < raiz -> dado) raiz = raiz -> esq;
        else raiz = raiz -> dir;
    }
    return raiz;
}
```

