#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *dir, *esq;
} celula;

celula *cria_arvore(){
    celula *raiz = malloc(sizeof(celula));
    raiz -> dir = NULL;
    raiz -> esq = NULL;
    raiz = NULL;

    return raiz;
}

celula *insere(celula *raiz, int dado){
    if(raiz == NULL){
        celula *novo = malloc(sizeof(celula));
        novo -> dado = dado;
        novo -> dir = novo -> esq = NULL;

        return novo;
    }

    if(raiz -> dado < dado) {
        raiz -> dir = insere(raiz -> dir, dado);
    }else if (raiz -> dado > dado){
        raiz -> esq = insere(raiz -> esq, dado);
    }

    return raiz;
}

void preOrdem(celula *raiz){
    if(raiz != NULL){
        printf("%d ", raiz -> dado);
        preOrdem(raiz -> esq);
        preOrdem(raiz -> dir);
    }
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

int main() {
    int numArvore = 0, numElementos = 0, num = 0;

    scanf("%d", &numArvore);
    
    for (int i = 0; i < numArvore; i++)
    {
        scanf(" %d", &numElementos);
        
        celula *raiz = NULL;
        
        for (int j = 0; j < numElementos; j++){
            scanf("%d", &num);
            raiz = insere(raiz, num);    
        }

        printf("Case %d:\n", i+1);
        printf("Pre.: ");
        preOrdem(raiz); printf("\n");
        printf("In..: ");
        emOrdem(raiz); printf("\n");
        printf("Post: ");
        posOrdem(raiz); printf("\n\n");
    }
    
    return 0;
}

