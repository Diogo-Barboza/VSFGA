#include <stdio.h>
#include <string.h>

#define MAX 1005

char mapa[MAX][MAX];
int visitado[MAX][MAX];

int fila_x[MAX * MAX];
int fila_y[MAX * MAX];
int fila_patos[MAX * MAX];
int ini = 0, fim = 0;

int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};

void empurra(int x, int y, int patos) {
    fila_x[fim] = x;
    fila_y[fim] = y;
    fila_patos[fim] = patos;
    fim++;
}

void bfs(int inicio_x, int inicio_y, int total_patos, int linhas, int colunas) {
    empurra(inicio_x, inicio_y, total_patos);

    int patos_salvos = 0;

    while (ini < fim) {
        int x = fila_x[ini];
        int y = fila_y[ini];
        int patos = fila_patos[ini];
        ini++;

        if (visitado[x][y]) continue;
        visitado[x][y] = 1;

        if (mapa[x][y] == 'E') {
            patos_salvos = patos;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= linhas || ny >= colunas) continue;

            char lugar = mapa[nx][ny];

            if (lugar == '#') continue;

            if (lugar == '_') {
                empurra(nx, ny, patos);
            } else if (lugar == 'o' && patos > 1) {
                mapa[nx][ny] = '_';
                empurra(nx, ny, patos - 1);
            } else if (lugar == 'E') {
                empurra(nx, ny, patos);
            }
        }
    }

    if (patos_salvos == 0) {
        printf("Todos morreram :)\n");
    } else if (patos_salvos == total_patos) {
        printf("Nenhum morreu :(\n");
    } else {
        printf("%d encontraram o vovo\n", patos_salvos);
    }
}

int main() {
    int P;
    scanf("%d", &P);
    getchar(); 

    int linhas = 0;
    int colunas = 0;
    int sx = -1, sy = -1;

    while (fgets(mapa[linhas], MAX, stdin)) {
        colunas = strlen(mapa[linhas]);
        if (mapa[linhas][colunas - 1] == '\n') {
            mapa[linhas][colunas - 1] = '\0';
            colunas--;
        }

        for (int j = 0; j < colunas; j++) {
            if (mapa[linhas][j] == 'S') {
                sx = linhas;
                sy = j;
            }
        }

        linhas++;
    }

    bfs(sx, sy, P, linhas, colunas);

    return 0;
}