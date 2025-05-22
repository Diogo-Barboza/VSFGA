# O problema de busca

Problema: Dado um conjunto S, verificar de um elemento x está ou não em S.
```c
int busca(int *v, int n, int x){
    for(int i=0; i < n; i++){
        if (v[i] == x) return i;
    }

    return -1;
} // Complexidade (O(n))
```
E se os elementos de S estiverem em ordem crescente?

<u>PROBLEMA</u>: Dado um conjunto S ordenado em ordem crescente, verificar se x pretence a S, devolver a posição que ocupa, ou a posição que deveria ocupar caso contrário.
Em outras palavras, dado v[0 ... n-1] e um elemento x, queremos determinar j tal que $v[j-1] < x <= v[j]$

Ex.:

n = 8

x = 15

|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|--|----|---|---|---|---|
| v | -3 | -1 | 1 | 7 | 10 | 15 | 18 | 21 |

1ª e = -1; m=(e+d)/2; d=n=8

```c
int buscaBinaria(int *v, int m, int x){
    int e = -1, d = n;
    while(e < d-1){
        int m = (e + d) / 2;
        if(x > v[m]) e = m;
        else d = m;
    }
    return d;
} // Complexidade: O(lg n)
```