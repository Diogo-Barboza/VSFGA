# Recursão

É uma função que chama-se a si mesma. Os problemas que podem ser resolvidos usando recursão são problemas que possuem **Estrutura Recursiva**. Um problema é recursivo se toda instância do problema for composta por instâncias menores do problema.

Ex.: Encontrar o maior elemento de um vetor.

Estrutura recursiva |--|--|--|--|--|

1. <u>Divide</u> a instância para chegar a uma instância menor.
2. Resolve a instância menor.
3. <u>Combina</u> as soluções das menores para resolver a maior.

Portanto, elaborar uma solução recursiva envolve:
1. Descobrir o caso trivial de se resolver.
2. Descobrir uma forma de dividir e... 
3. Descorbir uma forma de combinar.

---

Utilizando o exemplo:
1. Caso base: Vetor de tamanho 1
    - O maior elemento é o unico presente **O(1)**
2. Divisão: Reduzir as instâncias em uma unidade
3. Combinação: O maior será o maoir entre os elementos descartados e o maior da instância menor.

--- 

## Código

```C
int maio(int v[], int n){
    if(n==1) return v[0];
    else{
        int m = maior(v, v-1);
        if(m > v[v-1]) return m;
        else return v[n-1];
    }
}
```

## Teste de mesa

V =

| 0 | 1 | 2 | 3 | 4 |
|-- |---|---|---|---|
|-3 | 2 |-4 | -1| 7 |

-  **7** - maior(v, 5)
    - **2** - maior(v, 4)
        - **2** - maior(v, 3)
            - **2** - maior(v, 2)
                 - **-3** - maior(v, 1)


## Exemplo 2

Calcule $a^b$; com $b >= 0$; recursivamente -> $a \cdot a \cdot ... \cdot a; b$ vezes;

1. Caso base: $a^0 = 1$
2. Divisão: $a^b = a \cdot a^{b-1}$
3. Combinação = $a \cdot a^{b-1}$

```C
int exp(int a, int b){
    if(b==0) return 1;
    else return a * exp(a, b-1);
}
```

- Complexidade:
1. Tamanho da árvore de recursão
2. Teorema mestre

