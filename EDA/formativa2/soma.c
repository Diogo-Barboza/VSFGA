#include <stdio.h>

unsigned long long int soma(unsigned long long int num){
    if (num < 10) return num;

    return num%10 + soma(num / 10);
}

int main(){
    unsigned long long int entrada = 0;

    scanf("%llu", &entrada);

    printf("%llu\n", soma(entrada));

    return 0;
}