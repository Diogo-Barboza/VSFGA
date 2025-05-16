#include <stdio.h>
#include <string.h>

void moveX(char *v, int tamanho){
    char aux;

    if (v[i] == 'x')
    {
        v[tamanho] = v[i];
    }

    moveX(v, tamanho-1);
}

int main(){
    char ent[101];

    scanf("%s", ent);
    int tam = strlen(ent);

    moveX(ent, tam);

}
