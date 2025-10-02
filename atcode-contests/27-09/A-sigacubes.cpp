#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int formula(int i){
    return (pow((-1), i)) * (pow(i, 3));
}

int main(){
    int n;
    int soma = 0;

    cin >> n;
    
    
    for(int i = 1; i <= n; i++){
        soma += formula(i);
    }

    cout << soma << endl;

    return 0;
}