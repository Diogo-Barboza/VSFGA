#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;


    int desempilha (celula *p, int *y){
        if(p -> prox == NULL) return 0;
        celula *lixo = p -> prox;
        p -> prox = lixo -> prox;
        *y = lixo -> dado;
        free(lixo);
        return 1;
    }
