#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct celula {
    char cidade[27];
    struct celula *prox;
} celula;

void enfileira(celula **inicio, celula **fim, char *nome) {
    celula *novo = malloc(sizeof(celula));
    strcpy(novo->cidade, nome);
    novo->prox = NULL;

    if (*fim != NULL)
        (*fim)->prox = novo;
    else
        *inicio = novo;

    *fim = novo;
}

char primeira_letra(char *s) {
    return tolower(s[0]);
}

char ultima_letra(char *s) {
    return tolower(s[strlen(s) - 1]);
}

void processa_fila(celula *inicio) {
    celula *ini = inicio, *fim = NULL;

    celula *ptr = ini;
    while (ptr && ptr->prox)
        ptr = ptr->prox;
    fim = ptr;

    while (ini != NULL) {
        celula *atual = ini;
        printf("%s\n", atual->cidade);
        ini = ini->prox;
        char letra_final = ultima_letra(atual->cidade);
        free(atual);

        if (ini != NULL && primeira_letra(ini->cidade) == letra_final) {
            celula *mover = ini;
            ini = ini->prox;
            mover->prox = NULL;
            if (fim)
                fim->prox = mover;
            else
                ini = mover;
            fim = mover;
        }
    }
}
int main() {
    char cidade[27];
    celula *inicio = NULL, *fim = NULL;

    while (scanf("%s", cidade) != EOF) {
        enfileira(&inicio, &fim, cidade);
    }

    processa_fila(inicio);
    return 0;
}