#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int *v, int n){
    for(int i = 0; i < n; i++){
        for (int j = (i + 1); j >= 0 && v[j] > v[j + 1]; j--)
        {
            troca(&v[j], &v[j + 1]);
        }
    }
}



int main(){
    int v[1000], i = 0, j = 0;

    while (scanf("%d", &i) != EOF)
    {
        v[j] = i;
        j++;
    }

    insertion(v, j);

    for (int i = 0; i < j; i++){
        if (i == j){
            printf("%d", v[i]);
        }else {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
    
    return 0;
}