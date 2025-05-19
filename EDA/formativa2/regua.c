#include <stdio.h>

void hifen(int n){
    if (n == 0) return;
    printf("-");
    hifen(n - 1);
}

void traco(int n){
    printf(".");
    hifen(n);
    printf("\n");
}

void regua(int n){
    if (n == 0) return;
    regua(n-1);
    traco(n);
    regua(n-1);
}

int main(){
    int tam = 0;

    scanf("%d", &tam);

    regua(tam);

    return 0;
}