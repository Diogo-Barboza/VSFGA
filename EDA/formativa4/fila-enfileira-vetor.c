#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
}fila;


int enfileira (fila *f, int x){
    if ((f -> u+1) % f -> N == f -> p) {
        int *novo = malloc(f -> N * 2 * sizeof(int));
        if (novo == NULL) return 0;

        int i = 0;
        int j = f -> p;
        while (j != f -> u) 
        {
            novo[i++] = f -> dados[j];
            j = (j + 1) % f -> N;
        }

        free(f -> dados);
        f -> dados = novo;
        f -> p = 0;
        f -> u = i;
        f -> N *= 2;
    }

    f -> dados[f -> u] = x;
    f -> u = (f -> u + 1) % f -> N;

    return 1;
}