#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int buscaB(long long *raios, int n, long long x) {
    int e = -1, d = n;
    while (e + 1 < d) {
        int m = (e + d) / 2;
        if (x <= raios[m]) {
            d = m;
        } else {
            e = m;
        }
    }
    return d;
}

int main() {
    int C, T;
    scanf("%d %d", &C, &T);

    long long *raios = malloc(C * sizeof(long long));

    for (int i = 0; i < C; i++) {
        int r;
        scanf("%d", &r);
        raios[i] = (long long)r * r;
    }

    long long total_pontos = 0;

    for (int i = 0; i < T; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        long long distancia = (long long)x * x + (long long)y * y;

        int indice = buscaB(raios, C, distancia);
        int pontos = C - indice;

        total_pontos += pontos;
    }

    printf("%lld\n", total_pontos);

    free(raios);
    return 0;
}
