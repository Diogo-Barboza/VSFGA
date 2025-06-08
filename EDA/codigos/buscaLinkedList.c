#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *busca(celula *le, int x){
    for (celula *ptr = le; ptr != NULL; ptr = ptr -> prox){
        if(ptr -> dado == x) return ptr;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x){
    if ( le == NULL ) return NULL;
    if (le -> dado == x) return le;
    return busca_rec(le -> prox, x);
}

celula *cria_lista(){
    celula *le = malloc(sizeof(celula));

    le -> prox = NULL;

    return le;
}

void insere(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = le -> prox;
    le -> prox = novo;
}

void imprime(celula *le){
    printf("Lista: -> ");
    for (celula *ptr = le -> prox; ptr != NULL; ptr = ptr -> prox){
        printf("%d -> ", ptr -> dado);
    }
    printf("NULL\n");
}

int main(){
    celula *le = cria_lista();

    insere(le, 1);
    insere(le, 2);
    insere(le, 43);
    insere(le,90);
    insere(le, 100);
    insere(le, 110);

    imprime(le);

    celula *buscaNormal = busca(le->prox, 43);

    celula *buscaRecusiva = busca_rec(le->prox, 43);

    if(buscaNormal != NULL){
        printf("Found the value %d in the list!\n", buscaNormal->dado);
    } else {
        printf("Could not find the value %d in the list.\n", 43);
    }


    return 0;
}