#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int *v, int n){ // O n quadrado
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0 && v[j] < v[j-1]; j--)
        {
            troca(&v[j], &v[j-1]);
        } 
    }
}

int separa(int *v, int e, int d){
    int c = v[d];
    int j = e, k = e;
    while (k < d){
        if(v[k] <= c){
            troca(&v[k], &v[j]);
            j++;
        }
        k++;
    }
    troca(&v[j], &v[d]);
    return j;
}


void quickSort(int *v, int e, int d){
    if(e < d){
        int p = separa(v, e, d);
        quickSort(v, e, p-1);
        quickSort(v, p+1, d);
    }
}



int main(){

    int num[] = {
         87,  -42,   23,    5,  -19,   65,   99,  -78,   33,   12,
        -55,   76,   -2,   91,   49,   -63,   28,   82,   -11,   40,
         18,  -89,   71,   -7,   53,   96,   -30,   60,   -94,   25,
         -68,   44,   88,  -16,   79,   -35,    9,   58,   -83,   21,
          3,  -72,   67,   -24,   51,   93,   -48,   14,   -80,   37,
         75,  -10,   46,   -97,   20,   62,   -39,   85,    1,   -59,
        -22,   69,   -90,   13,   57,   -43,   81,   -17,   34,   98,
          6,  -66,   41,   -86,   29,   73,   -31,   50,   -95,   16,
        -47,   84,    0,   -61,   36,   -77,   55,   -28,   92,    8,
         32,  -53,   70,   -26,   47,  -99,   22,   64,   -14,   56
    };

    int tam = sizeof(num) / sizeof(num[0]);

    // insertion(num, 100);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d -> ", num[i]);
    // }

    // printf("\n");

    // int num[] = {3, -1, 7, 2, 4}; 

    quickSort(num, 0, tam-1);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", num[i]);
    }
    
    printf("\n");
    



    

    return 0;
}