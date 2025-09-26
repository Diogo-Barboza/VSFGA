# Knapsack

Também conhecido de algoritmo da mochila ou mochileiro. </br>

C = 11 Kg

| Item | Peso | Valor | v/p|
| ----|-----|---------|-|
| 1 | 3 | 30 | 10 |
| 2 | 4 | 36 | 9 |
| 3 | 2 | 16 | 8 |
| 4 | 1 | 7 |  7 |
| 5 | 3 | 18 | 6 |
| 6 | 4 | 24 | 6 |

| valor = 30 | C = 8 |
| ---------- | ----- |
|valor = 66 |C = 4 |
|valor = 82 | C = 2|
|valor = 89 |C = 1 |
|valor = 95 | C = 0|

Os pesos podem ser divisíveis, com objetico de lotar a mochila.

## Minimizar o tempo de atraso

- O trabalho j requer tj unidade de tempo para processar e tem que ser feito no tempo de dj (deadline).
- Se um trabalho j começa no tempo sj, termina com o tempo fj = sj + tj;
- lateness = lj = max(O, fj - dj)

| x | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|--|---|----|---|---|
|Tj| 3 | 2 | 1 | 4 | 3 | 2  |
|Dj| 6 | 8 | 9 | 9| 14 | 15 |


| d3 = 9 | d2 = 8 | d6 = 15 | d1 = 6 | d5 = 14 | d4 = 9 |
| ------- |-------|---------|--------|---------|--------|
| 0 - 1| 1-2-3 | 3-4-5 | 6-7-8 | 8-9-10-11| 11-12-13-14-15|

No 8, lateness = 2; No 11, lateness = 0; No 15, max lateness = 6; </br>

Subtrair o deadline do tempo que ela demora, você tem o slack, (jogo de cintura) para evitar o atraso. A ordem é assim:

- As com menos tempo de processamento (Tj). Contra exemplo:

| x | 1 | 2 |
|---|---|---|
| tj | 1 | 10 |
| dj | 100  |  10 |

- As com o menor "Slack". Contra exemplo:

| x | 1 | 2 |
|---|---|---|
| tj | 1 | 10 |
| dj | 2  |  10 |

- As com menos tempo de deadline (Dj)

```
Sort n jobs by deadline so that d1 <= d1 <- ... dn

t <- 0

for j = 1 to n
    assing job j to interval [t, t + tj]
    sj <- t, fj <- t + tj
    t <- t + tj
output intervals [sj, fj]
```
