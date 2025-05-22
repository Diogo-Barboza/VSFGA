# Algoritmos de Ordenação

## 1. Inserção

### Princípio: 

"Inserir" o i-ésimo elemento na posição "correta" do subvetor v[0 ... i - 1] 

Ex.: 

| 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 3 | -1 | 7 | 2 | 4 |

```c
void insertion()int *v, int n){
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j >= && v[j] > v[j+1], j--){
            troca(&v[j], &v[j + 1]);
        }
    }
}
```

> Complexidade $O(n^2)$ e $O(n)$ para um vetor já ordenado.

## 2. Seleção

### Princípio:

"Selecionar" o elemento do subvetor v[i  ... m - 1] e coloca na posição i.

Ex.:

| 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 2 | 5 | 1 | 0 | 3 |

```c
void selection(int *v, int n){
    for(int i = 0; i < n-1, i++){
        int menor = 1;
        for(int j = i + 1; j < n; j++)
            if(v[j] < v[menor]) menor = j;
        troca(&v[i], &v[menor]);
    }
}
```

## Estabilidade

Dizemos que o algoritmo de ordenação é <u>estável</u> se, ao ordenar, ele preserva a ordem original elementos iguais.

> Inserção é estável, mas a seleção não.

