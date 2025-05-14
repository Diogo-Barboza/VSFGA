#include <stdio.h>
#include <stdbool.h>

int num91(int n){
    if(n > 100) return n-10;
    return num91(num91(n+11));
}

int main(){
    int ent = 0;

    while (true)
    {
        scanf("%d", &ent);
        if(ent == 0) break;
        else{
            printf("f91(%d) = %d\n", ent, num91(ent));
        }

    }

    return 0;
}