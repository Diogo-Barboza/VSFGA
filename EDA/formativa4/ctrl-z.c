#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char dado[101];
    struct celula *prox;
} celula;

celula *cria_pilha() {
    celula *p = malloc(sizeof(celula));
    p->prox = NULL;
    return p;
}

void empilha(celula *p, char *str) {
    celula *novo = malloc(sizeof(celula));
    strcpy(novo->dado, str);
    novo->prox = p->prox;
    p->prox = novo;
}

void desfazer(celula *p) {
    if (p->prox == NULL) {
        printf("NULL\n");
        return;
    }
    celula *lixo = p->prox;
    printf("%s\n", lixo->dado);
    p->prox = lixo->prox;
    free(lixo);
}

int main() {
    char comando[110];
    celula *pilha = cria_pilha();

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "inserir") == 0) {
            char str[101];
            getchar(); 
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = 0; 
            empilha(pilha, str);
        } else if (strcmp(comando, "desfazer") == 0) {
            desfazer(pilha);
        }
    }

    return 0;
}