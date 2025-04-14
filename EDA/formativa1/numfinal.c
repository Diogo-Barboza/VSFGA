#include <stdio.h>
#include <math.h>

int encaixa(int a, int b){
    int temp = b, digitos = 0;
    while (temp > 0)
    {
        digitos++;
        temp /= 10;
    }
    int num = pow(10, digitos);

    if (a % num == b)
    {
        return 1;
    }else{
        return 0;
    }
    
}
