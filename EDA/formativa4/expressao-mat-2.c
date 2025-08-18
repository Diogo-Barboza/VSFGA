#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char dado;
    struct celula *prox;
}celula;

celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    if (p == NULL) return 0;

    p -> prox = NULL;

    return p;
}

int empilha(celula *p, char x){
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return 0;
    novo -> dado = x;
    novo -> prox = p -> prox;
    p -> prox = novo;
    return 1;
}

celula *desempilha(celula *p){
    if (p -> prox == NULL) return NULL;
    celula *lixo = p -> prox;
    p -> prox = lixo -> prox;
    return lixo;
}

int parentese(char *str){
    celula *p = cria_pilha();
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == '('){
            empilha(p, str[i]);
        }
        else if (str[i] == ')'){
            celula *c = desempilha(p);
            if (c == NULL || c -> dado != '(') return 0;
        }

        i++;
    }
    
    if (p -> prox != NULL) return 0;
    else return 1; 
}

int prioridade (char op){
    if (op == '^') return 3;
    if ( op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int associatividade(char op){
    if (op == '^') return 1;
    return 0;
}

int isOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void conversao(char *exp, char *saida){
    celula *p = cria_pilha();
    int i = 0, j = 0;

    while (exp[i] != '\0'){
        char c = exp[i];

        if (c >= 'A' && c <= 'Z'){
            saida[j++] = c;
        }
        else if (c == '('){
            empilha(p, c);
        }
        else if (c == ')'){
            while (p -> prox != NULL && p -> prox -> dado != '('){
                celula *topo = desempilha(p);
                saida[j++] = topo -> dado;
                free(topo);
            }
            if (p -> prox != NULL && p ->prox -> dado == '('){
                celula *abre = desempilha(p);
                free(abre);
            }
        }
        else if (isOperador(c)){
            while (p->prox != NULL && isOperador(p->prox->dado)) {
                char topo = p->prox->dado;
                if ((associatividade(c) == 0 && prioridade(c) <= prioridade(topo)) ||
                    (associatividade(c) == 1 && prioridade(c) < prioridade(topo))) {
                    celula *desemp = desempilha(p);
                    saida[j++] = desemp->dado;
                    free(desemp);
                } else break;
            }
            empilha(p, c);
        }

        i++;
        
    }

    while(p -> prox != NULL){
        celula *desemp = desempilha(p);
        saida[j++] = desemp -> dado;
        free(desemp);
    }
    saida[j] = '\0';
}

int main(){
    char exp[501];
    char saida[501];

    scanf("%s", exp);

    if(!parentese(exp)){
        printf("incorretamente parentizada\n");
        return 0;
    }

    conversao(exp, saida);
    printf("%s\n", saida);
    return 0;
}