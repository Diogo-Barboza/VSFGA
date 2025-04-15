#include <stdio.h>

int determina(int a, int b){

    int halfRetArea = ((70 * 160) / 2);
    int LeftTrapArea = ((a+b) * 70) / 2;
    int RightTrapArea = (((160-a) + (160-b)) * 70) / 2;
    
    if(halfRetArea == LeftTrapArea){
        return 0;
    }else if (LeftTrapArea > RightTrapArea)
    {
        return 1;
    }else if (LeftTrapArea < RightTrapArea)
    {
        return 2;
    }
    
}

int main() {
    int b = 0, t = 0;
    scanf("%d\n%d", &b, &t);

    printf("%d", determina(b, t));

    return 0;
}