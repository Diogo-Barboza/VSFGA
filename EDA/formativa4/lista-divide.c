#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

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

    par -> prox = NULL;
    impar -> prox = NULL;
}