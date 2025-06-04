#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordena(int *v, int n){
    if (n <= 1) return;
    
}

void insertion(int *v, int n){
    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 && v[j] < v[j-1] ; j--)
        {
            troca(&v[j], &v[j-1]);
        }
    }
}

int main(){

    return 0;
}