# include <stdio.h>
#include <stdlib.h>
#include <string.h>

int proxNaoX(char *ent, int pos){
    if (ent[pos] == '\0') return pos;

    if(ent[pos] != 'x') return pos;

    return proxNaoX(ent, pos+1);
}

void moveX(char *ent, int pos){
    if (ent[pos] == '\0') return;

    if (ent[pos] == 'x'){
        int j = proxNaoX(ent, pos + 1);
        if (ent[j] == '\0') return;
        char aux = ent[pos];
        ent[pos] = ent[j];
        ent[j] = aux;
    }

    moveX(ent, pos+1);
}

int main(){
    char ent[100] = "";

    scanf("%100s", ent);
    moveX(ent, 0);

    printf("%s\n", ent);

    return 0;
}