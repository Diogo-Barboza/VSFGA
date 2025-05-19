#include <stdio.h>
#include <string.h>

void troca(char *v, int pos){
    if (v[pos] == '\0') return;

    if (v[pos] == 'x') v[pos] = 'y';

    troca(v, pos+1);
}

int main(){
    char ent[80];

    scanf("%s", ent);

    troca(ent, 0);

    printf("%s", ent);

    return 0;
}