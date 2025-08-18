#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    if (f->dados == NULL || f->N == 0) {
        f->N = 10;
        f->dados = malloc(f->N * sizeof(int));
        if (f->dados == NULL) return 0;
        f->p = f->u = 0;
    }

    if ((f->u + 1) % f->N == f->p) {
        int novoN = f->N * 2;
        int *novo = malloc(novoN * sizeof(int));
        if (novo == NULL) return 0;

        int i = 0, j = f->p;
        
        while (j != f->u) {
            novo[i++] = f->dados[j];
            j = (j + 1) % f->N;
        }

        free(f->dados);
        f->dados = novo;
        f->p = 0;
        f->u = i;
        f->N = novoN;
    }

    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;

    return 1;
}