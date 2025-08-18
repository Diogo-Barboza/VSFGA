#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 501

typedef struct celula {
    char dado;
    struct celula *prox;
} celula;

celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    p->prox = NULL;
    return p;
}

void empilha(celula *p, char x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;
}

char desempilha(celula *p){
    if (p->prox == NULL) return '\0';
    celula *tmp = p->prox;
    char valor = tmp->dado;
    p->prox = tmp->prox;
    free(tmp);
    return valor;
}

char topo(celula *p){
    if (p->prox == NULL) return '\0';
    return p->prox->dado;
}

int prioridade(char op){
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int associatividade(char op){
    return op == '^'; // ^ é direita, outros são esquerda
}

int eh_operador(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int valida_parentese(const char *exp){
    celula *p = cria_pilha();
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') empilha(p, '(');
        else if (exp[i] == ')') {
            if (desempilha(p) == '\0') return 0;
        }
    }
    int ok = (p->prox == NULL);
    free(p);
    return ok;
}

void infixa_para_posfixa(const char *exp, char *saida){
    celula *p = cria_pilha();
    int j = 0;
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalpha(c)) saida[j++] = c;
        else if (c == '(') empilha(p, c);
        else if (c == ')') {
            while (topo(p) != '(') saida[j++] = desempilha(p);
            desempilha(p); // remove '('
        }
        else if (eh_operador(c)) {
            while (eh_operador(topo(p)) &&
                   ((associatividade(c) == 0 && prioridade(c) <= prioridade(topo(p))) ||
                    (associatividade(c) == 1 && prioridade(c) < prioridade(topo(p))))) {
                saida[j++] = desempilha(p);
            }
            empilha(p, c);
        }
    }
    while (topo(p)) saida[j++] = desempilha(p);
    saida[j] = '\0';
    free(p);
}

int avalia_posfixa(const char *exp, int *valores){
    int pilha[MAX];
    int topo = -1;
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalpha(c)) pilha[++topo] = valores[c - 'A'];
        else {
            int b = pilha[topo--];
            int a = pilha[topo--];
            if (c == '+') pilha[++topo] = a + b;
            else if (c == '-') pilha[++topo] = a - b;
            else if (c == '*') pilha[++topo] = a * b;
            else if (c == '/') pilha[++topo] = a / b;
            else if (c == '^') pilha[++topo] = (int)pow(a, b);
        }
    }
    return pilha[topo];
}

int main(){
    char exp[MAX];
    int valores[26] = {0};
    int usados[26] = {0};

    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0';

    if (!valida_parentese(exp)) {
        printf("emf\n");
        return 0;
    }

    for (int i = 0; exp[i]; i++) {
        if (isalpha(exp[i])) usados[exp[i] - 'A'] = 1;
    }

    for (int i = 0; i < 26; i++) {
        if (usados[i]) {
            char nome;
            int valor;
            scanf("%c=%d\n", &nome, &valor);
            valores[nome - 'A'] = valor;
        }
    }

    char posfixa[MAX];
    infixa_para_posfixa(exp, posfixa);

    int resultado = avalia_posfixa(posfixa, valores);
    printf("%d\n", resultado);

    return 0;
}
