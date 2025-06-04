#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int posicao;
} map;

void troca(map *a, map *b){
    map temp = *a;
    *a = *b;
    *b = temp; 
}

int buscaB(map *v, int n, int x){
    int e = -1, d = n;
    while (e < d-1)
    {
        int m = (e + d) / 2;
        if ( x > v[m].valor) e = m;
        else d = m;
    }
    if (d < n && v[d].valor == x)
        return v[d].posicao;
    else   
        return -1;
}

int separa(map *v, int e, int d){
    int c = v[d].valor;
    int j = e, k = e;
    while (k < d)
    {
        if(v[k].valor <= c){
            troca(&v[k], &v[j]);
            j++;
        }
        k++;
    }
    troca(&v[j], &v[d]);
    return j;
}

int quickSort(map *v, int e, int d){
    if(e < d){
        int p = separa(v, e, d);
        quickSort(v, e, p-1);
        quickSort(v, p+1, d);
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);
    map *v = malloc(n * sizeof(map));
    
    int i = 0;
    while ( i < n )
    {
        scanf("%d", &v[i].valor);
        v[i].posicao = i;
        i++;
    }

    quickSort(v, 0, n-1);
    
    i = 0;
    int ent = 0;
    while (i < m)
    {
        scanf("%d", &ent);
        printf("%d\n", buscaB(v, n, ent));
        i++;
    }
    
    free(v);
    
    return 0;
}