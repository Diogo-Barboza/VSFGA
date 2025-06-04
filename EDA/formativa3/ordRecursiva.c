#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insere(int *v, int j, int ultimo){
    if (j < 0 || v[j] <= ultimo) {
        v[j + 1] = ultimo;
        return;
    }

    v[j + 1] = v[j];
    insere(v, j - 1, ultimo); 
}

void ordena(int *v, int n){
    if (n <= 1) return;

    ordena(v, n-1);

    int ultimo = v[n-1];
    int j = n - 2;

    insere(v, j, ultimo);
}