#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int ch;
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula **t;
    int M;
} t_hash;

int hash(int ch, int M){
    return ch % M;
}

celula *buscar_lista(celula *le, int ch){
    if(le != NULL){
        for(celula *ptr = le -> prox; ptr != NULL; ptr = ptr -> prox){
            if(ptr -> ch == ch)
                return ptr;
        }
    }
    return NULL;
}

t_hash *cria_hash(int M){
    t_hash *h = malloc(sizeof(t_hash));
    h -> t = calloc(M, sizeof(celula *));
    h -> M = M;

    return h;
}

void inserir(t_hash *th, int ch, int dado){
    int i = hash(ch, th -> M);
    inserir_lista(th -> t[i], ch, dado);
}

void inserir_lista(celula *le, int ch, int dado){
    celula *ptr = le;
    while(ptr -> prox != NULL){
        ptr = ptr -> prox;
        if(ptr -> ch == ch) return; // Manipulação do dado AQUI !!!
    }

    celula *novo = malloc(sizeof(celula));
    novo -> dado = dado;
    novo -> prox = NULL;
    ptr -> prox = novo;
}

void remover(t_hash *th, int ch){
    int i = hash(ch, th -> M);
    remove_lista(th -> t[i], ch);
}

// Implementar remove_lista

celula *busca(t_hash *th, int ch){
    int i = hash(ch, th -> M);
    return buscar_lista(th -> t[i], ch);
}