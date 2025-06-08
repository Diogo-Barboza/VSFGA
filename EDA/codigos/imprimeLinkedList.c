#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void imprime (celula *le){
    for ( celula *ptr = le -> prox; ptr != NULL; ptr = ptr -> prox){
        printf("%d -> ", ptr -> dado);
    }
    printf("NULL\n");
}

void recursiva (celula *le){
    if (le == NULL) {
        printf("NULL\n");
        return;
    }
    else {
        printf("%d -> ", le->dado);
    }
    recursiva(le->prox);
}

void imprime_rec(celula *le){
    recursiva(le->prox);
}
 

