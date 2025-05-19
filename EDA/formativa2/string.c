#include <stdio.h>
#include <string.h>

void inverte(char *s, int tam){
    if(tam < 0) return;
    printf("%c", s[tam]);
    inverte(s, tam-1);
}

int main(){

    char string[510];
    scanf("%s", string);

    int tam = strlen(string);
    
    inverte(string, tam - 1);
    printf("\n");

    return 0;
}