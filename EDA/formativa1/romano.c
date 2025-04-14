#include <stdio.h>

void numRomano(int numero) {
    int nums[] =    {1000, 900, 500, 400, 100, 90,  50,  40,  10, 9,   5,  4,  1};
    char *romanos[] = {"M",  "CM", "D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    for (int i = 0; i < 13; i++) {
        while (numero >= nums[i]) {
            printf("%s", romanos[i]);
            numero -= nums[i];
        }
    }
    printf("\n");
}

int main() {
    int num;
    scanf("%d", &num);

    int valor;
    for (int i = 0; i < num; i++) {
        scanf("%d", &valor);
        numRomano(valor);
    }

    return 0;
}