#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

celula *cria_lista(){
    celula *le = malloc(sizeof(celula));

    le -> prox = NULL;

    return le;
}

void imprime(celula *le){
    for(celula *ptr = le -> prox; ptr != NULL; ptr = ptr -> prox){
        printf("%d -> ", ptr -> dado);
    }
    printf("NULL\n");
}

void insere(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = le -> prox;
    le -> prox = novo;
}

void divide_lista (celula *l, celula *l1, celula *l2){
    celula *impar = l1;
    celula *par = l2;
    celula *atual = l -> prox;

    while (atual != NULL){
       if ((atual -> dado) % 2 == 0 ){
           par -> prox = atual; 
           par = par -> prox;
       }else{
            impar -> prox = atual;
            impar = impar -> prox;
       }
       atual = atual -> prox;
    }
}

int main() {
    celula *p = cria_lista();
    celula *par = cria_lista();
    celula *impar = cria_lista();

    insere(p, 10);
    insere(p, 7);
    insere(p, 2);
    insere(p, -9);
    insere(p, 4);
    insere(p, 10);

    imprime(p);

    divide_lista(p, impar, par);

    imprime(par);
    imprime(impar);

    return 0;
}