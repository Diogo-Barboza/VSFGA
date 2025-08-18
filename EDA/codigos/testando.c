#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *esq, *dir;
}celula;

celula *insere(celula *raiz, int x){
    if(raiz == NULL){
        celula *novo = malloc(sizeof(celula));
        novo -> dado = x;
        novo -> esq = novo -> dir = NULL;

        return novo;
    }
    if (raiz -> dado > x)
        raiz -> esq = insere(raiz -> esq, x);
    else 
        raiz -> dir = insere(raiz -> dir, x);
    
        return raiz;
}

void preOrdem(celula *raiz){
    printf("%d ", raiz -> dado);
    preOrdem(raiz -> esq);
    preOrdem(raiz -> dir);
}

void emOrdem(celula *raiz){
    if(raiz != NULL){
        emOrdem(raiz -> esq);
        printf("%d ", raiz -> dado);
        emOrdem(raiz -> dir);
    }
}

void posOrdem(celula *raiz){
    if(raiz != NULL){
        posOrdem(raiz -> esq);
        posOrdem(raiz -> dir);
        printf("%d ", raiz -> dado);
    }
}

// PILHA -> lista encadeada
// FILA -> vetor com N, p, u; // FUDEU

void remove_sucessor(celula *raiz){
    celula *pai = raiz;
    celula *suc = raiz -> dir;

    while(suc -> esq != NULL){
        pai = suc;
        suc = suc -> esq;
    }

    raiz -> dado = suc -> dado;

    if(pai == raiz)
        pai -> dir = suc -> dir;
    else
        pai -> esq = suc -> dir;

    free(suc);
}

celula *remo_no(celula *raiz, int x){
    if (raiz == NULL) return NULL;
    if( x < raiz -> dado)
        raiz -> esq = remo_no(raiz -> esq, x);
    else if (x > raiz -> dado)
        raiz -> dir = remo_no(raiz -> dir, x);
    else {
        if(raiz -> esq == NULL){
            celula *ret = raiz -> dir;
            free(raiz);
            return ret;
        }
        else if(raiz -> dir == NULL){
            celula *ret = raiz -> esq;
            free(ret);
            return ret;
        }
        else{
            remove_sucessor(raiz);
        }
    }
    return raiz;
}


void rem(celula *raiz){
    celula *pai = raiz;
    celula *suc = raiz -> dir;

    while(suc -> esq != NULL){
        pai = suc;
        suc = suc -> esq;
    }

    raiz -> dado = suc -> dado;

    if(raiz == NULL){
        pai -> dir = suc -> dir;
    }else{
        pai -> esq = suc -> dir;
    }
    free(suc);
}

celula *tira(celula *raiz, int x){
    if(raiz == NULL) return NULL;
    if(x < raiz -> dado){
        raiz -> esq = tira(raiz -> esq, x);
    }else if(x > raiz -> dado){
        raiz -> dir = tira(raiz -> dir, x);
    }else{
        if(raiz -> esq == NULL){
            celula *ret = raiz -> dir;
            free(raiz);
            return ret;
        }
        else if(raiz -> dir == NULL){
            celula *ret = raiz -> esq;
            free(raiz);
            return ret;
        }
        else{
            remove(raiz);
        }
    }

    return raiz;
}