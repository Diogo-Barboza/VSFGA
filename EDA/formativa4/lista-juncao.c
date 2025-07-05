#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *fim = l3;
    celula *a = l1->prox;
    celula *b = l2->prox;

    while (a != NULL && b != NULL) {
        if (a->dado <= b->dado) {
            fim->prox = a;
            a = a->prox;
        } else {
            fim->prox = b;
            b = b->prox;
        }
        fim = fim->prox;
    }

    if (a != NULL)
        fim->prox = a;
    else
        fim->prox = b;
}
