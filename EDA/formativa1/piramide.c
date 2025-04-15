#include <stdio.h>

int menorDist(int a, int b){
    if (a < b || a == b)
    {
        return a;
    }else
    {
        return b;
    }
    
}

int main() {
    int tam;
    scanf("%d", &tam);

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf("%d", menorDist(menorDist(i + 1, j + 1), menorDist(tam - i, tam - j)));
        }
        printf("\n");
    }
    

    return 0;
}
