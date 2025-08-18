#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **inicio, celula **fim, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = NULL;
    if (*fim != NULL) {
        (*fim)->prox = novo;
    } else {
        *inicio = novo;
    }
    *fim = novo;
}

int desenfileira(celula **inicio, celula **fim) {
    if (*inicio == NULL) return -1;
    celula *temp = *inicio;
    int valor = temp->dado;
    *inicio = temp->prox;
    if (*inicio == NULL) *fim = NULL;
    free(temp);
    return valor;
}

int main() {
    int n;
    scanf("%d", &n);

    celula *inicio = NULL, *fim = NULL;

    for (int i = 1; i <= n; i++) {
        enfileira(&inicio, &fim, i);
    }

    printf("Cartas descartadas:");

    int primeira = 1;
    while (inicio != fim) {
        int desc = desenfileira(&inicio, &fim);
        if (!primeira) printf(",");
        printf(" %d", desc);
        primeira = 0;

        int move = desenfileira(&inicio, &fim);
        enfileira(&inicio, &fim, move);
    }

    printf("\nCarta restante: %d\n", inicio->dado);

    free(inicio);

    return 0;
}