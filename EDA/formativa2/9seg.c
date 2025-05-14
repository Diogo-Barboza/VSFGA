#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int grau9(char *n, char *nInicial ,int grau){
    int soma = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        soma += n[i] - '0';
    }
    if (soma < 10) {
        if (soma % 9 == 0) printf("%s is a multiple of 9 and has 9-degree %d.\n", nInicial, grau); 
        else printf("%s is not a multiple of 9.\n", nInicial);
        return soma;  
    }
    char nova_soma[1001];
    sprintf(nova_soma, "%d", soma); 
    return grau9(nova_soma, nInicial ,grau + 1);

}

int main(){
    char num[1001];

    while (true)
    {
        scanf("%s", num);
        if(strcmp(num, "0") == 0) break;

        grau9(num, num ,1);
    }
    
    return 0;
}