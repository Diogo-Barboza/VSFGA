#include <stdlib.h>
#include <stdio.h>

typedef struct pilha {
  int *dados;
  int N, topo;
} pilha;

pilha *cria_pilha(int tam){
    pilha *p = malloc(sizeof(pilha));
    p -> dados = malloc(tam * sizeof(int));

    p -> topo = 0;
    p -> N = tam;
    return p;
}

int empilha (pilha *p, int x){
    if ( p -> topo  == p -> N){
        p -> dados = realloc(p -> dados, 2 * p -> N * sizeof(int));
        if(p -> dados == NULL) return 1;
        p -> N *= 2;
    }
    p -> dados[p -> topo++] = x;
    return 0;
}

int desempilha (pilha *p, int *y){
    if (p -> topo == 0) return 1;
    p -> topo--;
    *y = p -> dados[p -> topo];
    return 0;
}


void destroi_pilha(pilha *p){
    free(p->dados);
    free(p);
}