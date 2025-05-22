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

## 3. Estabilidade

Dizemos que o algoritmo de ordenação é <u>estável</u> se, ao ordenar, ele preserva a ordem original elementos iguais.

> Inserção é estável, mas a seleção não.

## 4. Ordenação por Intercalação

A intercalação consiste em unir dois conjuntos ordenados em um só. Em termos de vetores: Dado um vetor v[e ... d] tal que v[e ... m] e v[m+1 ... d] são subvetores ordenados, para $e<=m<=d$, desejo qie v[0 .. n-1] fique ordenado.

```c
void intercala(int *v, int e, int d){
    int j = e, j = m, k = 0;
    int *aux = malloc((d - e + 1) * sizeof(int));
    while(i < m && j <= d){
        if(v[i] <= v[j]){
            aux[k] = v[i]; k++; j++;
        } else {
            aux[k] = v[j]; k++; j++;
        }
    }
    while(i<m) aux[k++] = v[i++];
    while(j<=d) aux[k++] = v[j++];

    for(k = 0; i = e; i <= d; k++; i++)
        v[i] = aux[k];

} // Complexidade: O(d - e + 1) 
```
## 5. MergeSort

```c
void mergesort(int *v, int e, int d){
    if(e<d){
        int m = (e + d) / 2;
        mergesort(v, e, m);
        mergesort(v, m+1, d);
        intercala(v, e, m, d);
    }

} // Complexidade O(n Lg n)
```
## 6. QuickSort

Baseia-se no problema da sepração. Dado um vetor v[e ... d], queremos um j tal que:
$$ 
v[e .. j-1] <= v[j] < v[j+1..d]
$$

Onde $v[e .. j-1]$ e $v[j+1..d]$, podem não estar **ordenados**.

Ex.: Estapas do quicksort

| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
| v =|2|-1|0|3|4|1|

> Onde, 1 é o pivô

| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
| v =|0|-1|1|3|4|2|

| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
| v =|0|-1|1|2|4|3|

| | 0 | 1 | 2 | 3 | 4 | 5 |
|-|---|---|---|---|---|---|
| v =|-1|0|1|2|3|4|

### Pior caso

O pior caso sera um vetor ordenado, pois ele não vai conseguir dividir o vetor, pois o pivô sempre vai estar no lugar certo.

Complexidade: $O(n^2)$

### O algoritmo da separação

| | e | | j | k | | | | d |
|-|---|-|-|-|-|-|-|-|
|v= | <=c | <=c | >e | ? | ? | ? | ? | ? |

Se $v[k]<= c$, troca v[k] com v[j] e incrementa j.

```c
int separa(int *v, int e, int d){
    int c = v[d];
    int j = e, k = e;
    while(k < d){
        if(v[k] <= c){
            troca(&v[k], &v[j]);
            j++;
        }
    }
    k++;
    troca(&v[j], &v[d]);
    return j;
}
```

### Algoritmo QuickSort

```c
void quicksort(int *v, int e, int d){
    if(e < d){
        int p = separa(v, e, d);
        quicksort(v, e, p-1);
        quicksort(v,p+1, d);
    }
}
```

Complexidade: $O(n^2)$

### Observáveis

- O pior caso do QuickSort é quando separa sempre retorna d. Isso pode acontece quando o vetor já esteja ordenado.
- Há uma implementação do QuickSort em C, na **stdlib.h**.

```void qsort(void *v, int n, int size_memb, int(compara)(void *a, void *b))```

Temos um jeito de melhorar o quicksort, que é mudando o pivô, trocando com a mediana do vetor. Podemos usar uma função pra fazer isso:

```c
int mediana3(int e, int m, int d){
    int a = v[e], b = v[m], c = v[d];
}

void quicksort(int *v, int e, int d){
    if(e<d){
        int m = mediana3(e, (e+d)/2, d);
        troca(&v[m], &v[d]);
        int p = separa(v, e, d);
        quicksort(v , e , p-1);
        quicksort(v, p+1, d);
    }
}
```

## 7. QuickSelect

Problema: encontrar o k-ésimo menor elemento de um vetor v[0 ... n-1], para $0 <= k < m$. 

```c
void quickselect(int *v, int e, int d, int k){
    if(e < d){
        int m = mediana3(e, (e+d)/2, d);
        troca(&v[m], &v[d]);

        int p = separa(v, e, d);

        if(k < p) quickselect(v, e , p-1, k);
        if(k > p) quickselect(v, p+1 , d, k);
    }
}
``` 

### Observações

- O pior caso do QuickSelect é o mesmo do QuickSort em termos de instância e complexidade.
- Além de encontrar o k-ésimo menor elemento, o QuickSelect reordena os elementos de v tal que:

$$
V[0 ... k - 1] <= v[k] < v[k ... n - 1]
$$

Isso pode ser muito eficiente para ordenar apenas uma parte do vetor.

