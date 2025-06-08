#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_lista(){
    celula *le = malloc(sizeof(celula));

    le -> prox = NULL;

    return le;
}

celula *busca(celula *le, int x){ //Busca Iterativa
    for (celula *ptr = le; ptr != NULL; ptr = ptr -> prox){
        if(ptr -> dado == x) return ptr;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x){ // Busca recursiva
    if ( le == NULL ) return NULL;
    if (le -> dado == x) return le;
    return busca_rec(le -> prox, x);
}

void insere(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = le -> prox;
    le -> prox = novo;
}

int removelista(celula *ptr){ // Corrigida
    celula *lixo = ptr -> prox;
    celula *proxNo = lixo -> prox;
    int x = lixo -> dado;
    ptr -> prox = proxNo;
    
    free(lixo);
    return x;
}


void imprime(celula *le){
    for (celula *ptr = le -> prox; ptr != NULL; ptr = ptr -> prox){
        printf("%d -> ", ptr -> dado);
    }
    printf("NULL\n");
}

void recursiva (celula *le){ 
    if (le == NULL) {
        printf("NULL\n");
        return;
    }
    else {
        printf("%d -> ", le->dado);
    }
    recursiva(le->prox);
}

void imprime_rec(celula *le){
    recursiva(le->prox);
}

int main(){
    celula *le = cria_lista();

    insere(le, 1);
    insere(le, 2);
    insere(le, 43);
    insere(le,90);
    insere(le, 100);
    insere(le, 110);

    imprime(le);

    imprime_rec(le); // Comecar depois do no Cabeca

    celula *buscaNormal = busca(le->prox, 90); // Quero eliminar essa cel

    celula *buscaRecusiva = busca_rec(le->prox, 43);

    if(buscaNormal != NULL){
        printf("Achei o valor %d na lista!\n", buscaNormal->dado);
    } else {
        printf("Nao foi encontrado o valor %d na lista.\n", buscaNormal->dado);
    }

    printf("%d\n", removelista(le)); // remove o primeiro nó

    imprime_rec(le);    

    return 0;
}