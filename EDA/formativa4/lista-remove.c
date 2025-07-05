#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

void remove_depois(celula *p){
    if ( p -> prox == NULL){
        return;
    }
    celula *lixo = p -> prox;
    celula *proxno = lixo -> prox;
    p -> prox = proxno;

    free(lixo);
}

void remove_elemento (celula *le, int x){
    for ( celula *atual = le; atual != NULL; atual = atual -> prox){
        if ( atual -> prox == NULL ){
            return;
        }
        else if ( atual -> prox -> dado == x){
            celula *lixo = atual ->prox;
            atual -> prox = lixo -> prox;

            free(lixo);
            return;
        }
    }
}

void remove_todos_elementos (celula *le, int x){
    celula *atual = le;
    while ( atual -> prox != NULL){
        if ( atual -> prox -> dado == x)
        {
            celula *lixo = atual -> prox;
            atual -> prox = lixo -> prox;
            free(lixo);
        }else{
            atual = atual -> prox;
        }
    }
}
