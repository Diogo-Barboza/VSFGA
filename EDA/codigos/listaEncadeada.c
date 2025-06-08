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

void insere(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = le -> prox;
    le -> prox = novo;
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


int removelista(celula *ptr){ // remove head
    celula *lixo = ptr -> prox;
    celula *proxNo = lixo -> prox;
    int x = lixo -> dado;
    ptr -> prox = proxNo;
    
    free(lixo);
    return x;
}

int removeItem(celula *le, int x){
    for ( celula *atual = le; atual != NULL; atual = atual -> prox){
        if ( atual -> prox -> dado == x){
            celula *to_remove = atual -> prox;

            atual -> prox = to_remove -> prox;

            free(to_remove);

            return 1;
        }
    }
    return 0; // 0 se n econtrou
}

int removeUltimo(celula *le){
    if(le -> prox == NULL) return 0; 

    for (celula *atual = le; atual != NULL; atual = atual -> prox){
        if ( atual -> prox -> prox == NULL) {
            free(atual->prox);
            atual -> prox = NULL;
            return 1;
        }
    }
    return 0;
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

void destroi_lista(celula *le){
    while(le -> prox != NULL){
        removelista(le);
    }
    free(le);
}

int main(){
    celula *le = cria_lista();

    insere(le, 1);
    insere(le, 2);
    insere(le, 43);
    insere(le, 90);
    insere(le, 100);
    insere(le, 110);

    imprime(le);

    imprime_rec(le); // Comecar depois do no Cabeca

    celula *buscaNormal = busca(le->prox, 90); // cell exitente

    celula *buscaRecusiva = busca_rec(le, 3); // Cell que nao existe

    if(buscaNormal != NULL){
        printf("Achei o valor %d na lista!\n", buscaNormal->dado);
    } else {
        printf("Nao foi encontrado o valor %d na lista.\n", buscaNormal->dado);
    }

    if(buscaRecusiva != NULL){
        printf("Achei o valor %d na lista\n", buscaRecusiva->dado);
    }else{
        printf("Nao achei o valor %d na lista\n", 3);
    }

    printf("A primeira celula de valor %d foi removida\n", removelista(le)); // remove o primeiro nó

    imprime_rec(le);

    printf("Testando remover um elemento y = 43\n");
    removeItem(le, 43);
    imprime(le);

    printf("Testando remover o último elemento\n");
    removeUltimo(le);
    imprime_rec(le);

    destroi_lista(le);

    return 0;
}