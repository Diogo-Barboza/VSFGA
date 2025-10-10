#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int janelaTempo;
} processo;

processo *cria_processos(int tam){
    processo *processos = malloc(tam * sizeof(processo));
    return processos;
}

static void roundRobin(processo processos[], int n, int tempoExecucao)
{
    if (n <= 0) {
        return;
    }

    if (n == 1) {
        printf("%d (%d)\n", processos[0].pid, processos[0].janelaTempo);
        return;
    }

    int tempoTotal = 0, atual = 0, final = n - 1;

    while (final > 0) {
        int tempodeExecucao = processos[atual].janelaTempo < tempoExecucao ? processos[atual].janelaTempo : tempoExecucao;

        tempoTotal += tempodeExecucao;
        processos[atual].janelaTempo -= tempodeExecucao;

        if (processos[atual].janelaTempo == 0) {
            printf("%d (%d)\n", processos[atual].pid, tempoTotal);

            for (int i = atual; i < final; ++i){
                processos[i] = processos[i + 1];
            }
            --final;
        } else {
            ++atual;
        }

        if (atual > final){
            atual = 0;
        }
    }

    printf("%d (%d)\n", processos[0].pid, tempoTotal + processos[0].janelaTempo);
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0){
        return 0;
    }

    int tempoExecucao;
    scanf("%d", &tempoExecucao);

    processo *p = cria_processos(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].pid, &p[i].janelaTempo);
        p[i].janelaTempo *= 1000;
    }

    roundRobin(p, n, tempoExecucao);
    return 0;
}