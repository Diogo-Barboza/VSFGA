#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *esq, *dir;
} celula;

celula *busca(celula *raiz, int x){
    if (raiz == NULL || raiz -> dado == x){
        return raiz;
    }
    if(raiz -> dado > x){
        return busca(raiz -> esq, x);
    }else{
        return busca(raiz -> dir, x);
    }
}

celula *insere(celula *raiz, int x){
    if (raiz == NULL) { 
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

void remove_sucessor(celula *raiz){
    celula *pai = raiz;
    celula *suc = raiz -> dir;

    while (suc -> esq != NULL){
        pai = suc;
        suc = suc -> esq;
    }

    raiz -> dado = suc -> dado;

    if (pai == raiz)
        pai -> dir = suc -> dir;
    else {
        pai -> esq = suc -> dir;
    }
    
    free(suc);
}

celula *remove_no(celula *raiz, int x){
    if (raiz == NULL) return NULL;
    if (x < raiz -> dado)
        raiz -> esq = remove_no(raiz -> esq, x);
    else if (x > raiz -> dado)
        raiz -> dir = remove_no(raiz -> dir, x);
    else{
        if(raiz -> esq == NULL){
            celula *ret = raiz -> dir;
            free(raiz);
            return ret;
        }else if (raiz -> dir == NULL){
            celula *ret = raiz -> esq;
            free(raiz);
            return ret;
        }else{
            remove_sucessor(raiz);
        }
    }

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

int main(){
    celula *raiz = NULL;

    raiz = insere(raiz, 15);
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 20);
    raiz = insere(raiz, 25);
    raiz = insere(raiz, 18);

    
    celula *achei = remove_no(raiz, 20);

    if(achei != NULL){
        printf("dado: %d\n", achei -> dado);
    }

    emOrdem(raiz);

    return 0;
}