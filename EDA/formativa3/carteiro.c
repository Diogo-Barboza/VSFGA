#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int casa;
    int posicao;
} map;

int contaPassos(int ini, int fim){
    int res = ini - fim;
    if (res < 0) return (-1 * res);
    
    return res;
}

int busca(map *v, int n, int x){
    for (int i = 0; i < n; i++)
    {
        if (v[i].casa == x)
        {
            return v[i].posicao;
        }
    }
}

int main(){
    int n = 0, m = 0;
    // n = numero das casas na ordem da rua
    // m = numero das casas na ordem da entrega

    scanf("%d %d", &n, &m);

    map *vn = malloc(n * sizeof(map));
    int *vm = malloc(m * sizeof(int));

    for (int i = 0; i < n; i++){ // mapeia as casas
        scanf("%d", &vn[i].casa);
        vn[i].posicao = i;
    }
    for (int i = 0; i < m; i++) scanf("%d ", &vm[i]); 

    int soma = 0, posicao = 0;

    for (int i = 0; i < m; i++){
        int destino = busca(vn, n, vm[i]);
        soma += contaPassos(posicao, destino);
        posicao = destino;
    }
    
    printf("%d\n", soma);

    return 0;
}