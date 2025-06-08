#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *criar_lista(){
    celula *le = malloc(sizeof(celula));

    le -> prox = NULL;

    return le;
}

celula *busca(celula *le, int x){
    for(celula *ptr; ptr != NULL; ptr = ptr -> prox){
        if(ptr -> dado == x) return ptr;
        return NULL;
    }
}

void insere(celula *ptr, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = ptr -> prox;
    ptr -> prox = novo;
}

int remove(celula *ptr){ // celula anterior
    celula *lixo = ptr -> prox;
    int x = ptr -> dado;
    ptr -> prox = lixo -> prox;
    free(ptr);
    return x;
}

int main(){

    
    
    
    return 0;
}