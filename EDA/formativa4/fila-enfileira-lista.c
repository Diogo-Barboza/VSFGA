#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

celula *cria_fila(){
    celula *f = malloc(sizeof(celula));

    f -> prox = NULL;

    return f;
}

celula *enfileira (celula *f, int x){
    celula *novo = malloc(sizeof(celula));

    novo -> prox = f -> prox;
    f -> dado = x;
    f -> prox = novo;

    return novo;
}