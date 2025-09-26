#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no *esq, *dir;
} no;

void posOrdem(no *raiz){
    if(raiz != NULL){
        posOrdem(raiz -> esq);
        posOrdem(raiz -> dir);
        printf("%c", raiz -> dado);
    }
}

no *insere(no *raiz, char dado){
    if(raiz == NULL){
        no *novo = malloc(sizeof(no));
        novo -> dado = dado;
        novo -> esq = novo -> dir = NULL;

        return novo;
    }

    if(raiz -> dado > dado)
        raiz -> esq = insere(raiz -> esq, dado);
    else
        raiz -> dir = insere(raiz -> dir, dado);

    return raiz;
}

int main() {
    char preOrdem[26], emOrdem[26], saida[25];
    
    while (scanf("%s %s", preOrdem, emOrdem) != EOF){
        no *raiz = NULL;
        
        for(int i = 0; i < strlen(preOrdem); i++){
            raiz = insere(raiz, preOrdem[i]);
        }

        posOrdem(raiz); printf("\n");
    }
    
    return 0;
}


 