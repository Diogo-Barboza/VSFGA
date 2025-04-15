# Introdução

## Como medir o desempenho de algoritmo?

- Tempo de execução
- Memória
Entretando, essas duas podem variar e existe um **trade off** entre elas.
- Linguagem de programação e compilador
- Quantidade de operações
    - Única que não é variável.


## Problema: Encontrar o maior valor de um vetor.

```C
int main(){
    int v[10];
    int maior = v[0]; // Custo de 1 para alocação de memória
    for(int i = 1; i < 10; i++){ // (1 alocação)(n para iteração)(n-1 para soma de i)
        if(v[i] > maior){ // n-1 iteração
            maior - v[i]; // no pior caso n-1
        }
    }
    printf("o maior é: %d", maior);
}
```

Portanto, somanto todos os custos -> <= 1 + 1 + n + n - 1 + n - 1 + n - 1 + 1. Ou seja, <= 4n.

Tipos Primitivos | Modificadores
---------------- | -------------
**1B** char      | short
**4B** int       | long
**4B** float     | unsigned
**8B** double    |

- long: inteiro de 64 bits. (8B ou 12B)
