#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *esq, *dir;
}celula;

celula *cria_arvore(int x){
    celula *raiz = malloc(sizeof(celula));
    raiz -> dir = NULL;
    raiz -> esq = NULL;
    raiz -> dado = x;

    return raiz;
}

celula *insere(celula *raiz, int x){
    if (raiz == NULL){
        celula *novo = malloc(sizeof(celula));
        novo -> dado = x;

        novo -> esq = novo -> dir = NULL;

        return novo;
    }

    if(raiz -> dado > x){
        raiz -> esq = insere(raiz -> esq, x);
    }else{
        raiz -> dir = insere(raiz -> dir, x);
    }
    
    return raiz;
}

int main () {
    celula *raiz = cria_arvore(54);

    printf("%d \n", raiz -> dado);

    insere(raiz, 40);
    insere(raiz, 60);

    printf("%d \n", raiz -> dir -> dado);
    printf("%d \n", raiz -> esq -> dado);

    return 0;
}