#include <stdio.h> 
#include <stdlib.h>

int buscaBinaria(int *v, int n, int x){
    int e = -1, d = n;
    while (e < d-1)
    {
        int m = (e + d)/2;
        if ( x > v[m] ) e = m;
        else d = m;
    }
    return d;
}

int main(){

    int n=0, m=0, entM;

    scanf("%d %d", &n, &m);

    int *v = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &entM);

        int indice = buscaBinaria(v, n, entM);

        printf("%d\n", indice);
    }

    free(v);

    return 0;
}