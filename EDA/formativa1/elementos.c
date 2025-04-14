#include <stdio.h>

int main (){
    int n, ent, cont = 0;
    long long int  soma = 0;
    int out[100000];
    scanf("%d", &n);

    int num[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ent);
        soma += ent;
        num[i] = ent;
    }
    
    int med = soma / n;

    for (int i = 0; i < n; i++)
    {
        if (num[i] > med)
        {
            out[cont] = num[i];
            cont++;
        }
    }

    if (cont == 0)
    {
        printf("%d\n", 0);
    }else{
        for (int i = 0; i < (cont-1); i++)
        {
            printf("%d ", out[i]);
        }
        printf("%d\n", out[cont-1]);
    }
    
    return 0;
}