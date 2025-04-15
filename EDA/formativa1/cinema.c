# include <stdio.h>
#include <stdlib.h>

int main() {
    int f, l;
    scanf("%d %d", &f, &l);

    int sala[f][l];
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < l; j++)
        {
            sala[i][j] = 0;
        }
    }
    

    char letra;
    int n = 0;

    while (scanf(" %c%d", &letra, &n) != EOF)
    {
        int i = letra - 'A';
        sala[i][n-1] = 1;
    }

    printf("  ");

    for (int i = 0; i < l; i++)
    {
        if (i < 9) printf("0%d ", i+1);
        else printf("%d ", i+1);
    }
    printf("\n");
    
    for (int i = f-1; i >= 0; i--)
    {
        char t = i + 'A';
        printf("%c ", t);

        for (int j = 0; j < l; j++)
        {
            printf("%s ", sala[i][j] ? "XX" : "--");
        }
        printf("\n");
    }

    return 0;
}