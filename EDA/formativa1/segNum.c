#include <stdio.h>
#include <math.h>

int encaixa(int a, int b){
    char strA[20], strB[20];
    sprintf(strA, "%d", a);
    sprintf(strB, "%d", b);

    int tamA = strlen(strA);
    int tamB = strlen(strB);

    if (tamB > tamA)
        return 0;

    if (strcmp(strA + tamA - tamB, strB) == 0)
        return 1;   
    else
        return 0;
    
}


int segmento(int a, int b) {
    char strA[20], strB[20];
    sprintf(strA, "%d", a);
    sprintf(strB, "%d", b);

    if (encaixa(a, b) || encaixa(b, a)) return 1;

    if (strlen(strA) < strlen(strB)) {
        return strstr(strB, strA) != NULL;
    } else {
        return strstr(strA, strB) != NULL;
    }
}