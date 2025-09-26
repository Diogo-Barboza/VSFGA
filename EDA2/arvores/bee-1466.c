#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *esq, *dir;
} celula;

typedef struct no_fila {
    celula *dado;
    struct no_fila *prox;
} no_fila;

typedef struct fila {
    no_fila *ini, *fim;
} fila;

fila *cria_fila(){
    fila *fila = malloc(sizeof(fila));
    fila -> ini = fila -> fim = NULL;

    return fila;
}

void enfileira(fila *f, celula *x){
    no_fila *novo = malloc(sizeof(no_fila));
    novo -> dado = x;
    novo -> prox = NULL;
    if(f -> fim)
        f -> fim -> prox = novo;
    else
        f -> ini = novo;
    
    f -> fim = novo;
}

celula *desinfileira(fila *f){
    if(f -> ini == NULL) return NULL;

    no_fila *lixo = f -> ini;
    celula *ret = lixo -> dado;
    f -> ini = lixo -> prox;
    if(f -> ini == NULL) f -> fim = NULL;
    free(lixo);

    return ret;
}


celula *insereArvore(celula *raiz, int x){
    if(raiz == NULL){
        celula *novo = malloc(sizeof(celula));
        novo -> dado = x;
        novo -> esq = novo -> dir = NULL;

        return novo;
    }

    if(raiz -> dado > x){
        raiz -> esq = insereArvore(raiz -> esq, x);
    }else if (raiz -> dado < x){
        raiz -> dir = insereArvore(raiz -> dir, x);
    }

    return raiz;
}

void porAltura(celula *raiz){
    if (!raiz) return;
    fila *f = cria_fila();
    enfileira(f, raiz);
    while (f -> ini != NULL)
    {
        celula *atual = desinfileira(f);
        printf("%d ", atual -> dado);
        if(atual -> esq) enfileira(f, atual -> esq);
        if(atual -> dir) enfileira(f, atual -> dir);
    }
    free(f);
}

int main(){
    int numArvore = 0, numElementos = 0, num = 0;

    scanf("%d", &numArvore);

    for(int i = 0; i < numArvore; i++){

        celula *raiz = NULL;
        scanf("%d", &numElementos);
        for (int j = 0; j < numElementos; j++)
        {
            scanf("%d", &num);
            raiz = insereArvore(raiz, num);
        }

        printf("Case %d:\n", i+1);
        porAltura(raiz); printf("\n\n");   
    }

    return 0;
}