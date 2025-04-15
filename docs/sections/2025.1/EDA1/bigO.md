# Introdução a complexidade e Big-O

Contar a quantidade de operações é difícil, as vezes, é até viável, a ideia é medir <u>ordem de grandeza</u> de quantiade de operações:

- **Como o total de operações cresce ao longo que o tamanho cresce?** Por meio da anotação assintótica.

Dizemos que uma função $f: \mathbb{N} \to \mathbb{N}$ é $O(g(n))$, com $g: \mathbb{N} \to \mathbb{N}$. Se existem constantes $C \in \mathbb{N}_0$ tais que: 

$$
f(n) \leq c \cdot g(n), \quad \forall n \geq n_0
$$

## Medidas Padrão

- $O(1)$ : Constante
- $O(\log n)$ : Logarítmico
- $O(n \log n)$ : Linearítmico
- $O(n^2)$ : Quadrático
- $O(n^k)$ : K - Polinomial
- $O(k^n)$ : Exponencial
- $O(n!)$ : Fatorial

Com isso, os problemas passasm a ser classificados de acordo com a complexidade do **melhor algoritmo que o resolve**.

## Casos de Análise de Complexidade

- Acessar o i-ésimo elemento do vetor v:
    - $V[i] = O(1)$
    - Qual o endereço de memória ocupa v[i]?
        - $Endereço Base + 4 \times i$

Importante olhar para a iteração em sí:

- Complexidade: $O(n)$
```c
for(int i = 0; i < n; i++){
    /* O(1) */
}
```
- Complexidade: $O(1)$
```C
for(int i = 0; i < 1000000; i++){
    /* O(1) */
}
```

- Complexidade: $O(n^2)$
```C
for(int i = 0; i < n; i++){
    for(int j = 0; i < n; i++){
        /* O(1)*/
    }
}
```

- Complexidade: $O(n \times m)$
```C
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        /* O(1) */
    }
}
```

- Complexidade: $O(n^2)$
```C
for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
        /* O(1) */
    }
}
```

$$
S = (0 + n-1) \times \frac{n}{2} = \frac{1}{2} n^2 - \frac{1}{2} n
$$

### Multiplicação de matrizes

$$
C_{ij} = 2_{k=1}^m A_{ik} \cdot B_{kj}
$$

- Complexidade: $O(n \cdot m \cdot p)$ 

```C
for(int i = 0; i < n; i++){
    for(int j=0; j < p; j++){
        C[i][j] = 0;
        for(int k = 0; k < m; k++){
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

## Regra geral

A complexidade de um algoritmo é a soma das complexidades de seus blocos não aninhados. Nesse sentido, a complexidade sera aquela do **bloco mais caro**.

- Ex.:
    $$
    O(n) + O(n^2) + O(n^3) = O(n + n^2 + n^3) = O(n^3)
    $$

- Complexidade: $O(\log n)$

```C
for(int i = 1; i < n; i *= 2){
    /* O(1) */
}
```

- Complexidade: $O(n)$

```C
for(int i = 0; i > 0; i /= 2){
    for(int j = 0; j < i; j++){
        /* O(1) */
    }
}
```