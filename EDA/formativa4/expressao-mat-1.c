#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char dado;
    struct celula *prox;
}celula;

celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    if (p == NULL) return NULL;
    p -> prox = NULL;

    return p;
}

void empilha(celula *p, char x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = p -> prox;
    p -> prox = novo;
}

celula *desempilha(celula *p){
    if (p -> prox == NULL) return NULL;
    celula *lixo = p -> prox;
    p -> prox = lixo -> prox;

    return lixo;
}

int expressao(char *exp){
    celula *p = cria_pilha();
    
    int i = 0;
    while(exp[i] != '\0') {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            empilha(p, exp[i]);
        else if (exp[i] == ')'){
            celula *c = desempilha(p);
            if (c == NULL || c -> dado != '(') return 0;
        }
        else if (exp[i] == ']'){
            celula *c = desempilha(p);
            if (c == NULL || c -> dado != '[') return 0;
        }
        else if (exp[i] == '}'){
            celula *c = desempilha(p);
            if (c == NULL || c -> dado != '{') return 0;
        }
        
        i++;
        
    }

    if (p -> prox != NULL) return 0;
    else return 1;
}

int main(){
    celula *p = cria_pilha();
    char exp[500];

    scanf("%[^\n]s", exp);

    int correto = 1;

    int i = 0;
    while(exp[i] != '\0') {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            empilha(p, exp[i]);
        else if (exp[i] == ')'){
            celula *c = desempilha(p);
            if (c == NULL || c -> dado != '('){
                correto = 0;
                break;
            } 
        }
        else if (exp[i] == ']'){
            celula *c = desempilha(p);
            if (c == NULL || c -> dado != '['){
                correto = 0;
                break;
            }
        }
        else if (exp[i] == '}'){
            celula *c = desempilha(p);
            if (c == NULL || c -> dado != '{'){
                correto = 0;
                break;
            }
        }
        
        i++;
    
    }

    if (p -> prox != NULL) correto = 0;

    printf("%s\n", correto ? "sim" : "nao");

    return 0;
}