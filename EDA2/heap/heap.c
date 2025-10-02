#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int size;
    int* v;
} heap;

heap* cria_heap(int capacidade){
    heap* h = malloc(sizeof(heap));
    h -> size = 0;
    h -> v = malloc((capacidade + 1) * sizeof(int));

    return h;
}

void fixUp(heap* h, int i){
    if(i <= 1) return;
    int pai = i / 2;
    if(h -> v[pai] < h -> v[i]){
        int temp = h -> v[pai];
        h -> v[pai] = h -> v[i];
        h -> v[i] = temp;
    }
    fixUp(h, pai);
}

void insere(heap* h, int x){
    h->v[++h->size] = x;
    fixUp(h, h->size);
}

void fixDown(heap* h, int i){
    int filho;
    while(i * 2 <= h -> size){
        filho = i * 2;
        if(filho != h -> size && h -> v[filho] < h -> v[filho + 1])
            filho++;
        if(h -> v[i] < h -> v[filho]){
            int temp = h -> v[filho];
            h -> v[filho] = h -> v[i];
            h -> v[i] = temp;
            i = filho;
        }else return;
    }
}

void pop(heap* h){
    int temp = h -> v[1];
    h -> v[1] = h -> v[h -> size];
    h -> v[h ->size] = temp;
    h -> size--;
    fixDown(h, 1);
    printf("%d foi retirado da heapmax\n", temp);
}

int peek(heap* h){
    return h -> v[1];
}

int main() {

    heap* pq = cria_heap(100);
    insere(pq, 10);
    insere(pq, 20);
    insere(pq, 30);
    insere(pq, 40);
    printf("%d has the highest priority\n", peek(pq));
    pop(pq);
    pop(pq);
    printf("%d has the highest priority\n", peek(pq));

    return 0;
}