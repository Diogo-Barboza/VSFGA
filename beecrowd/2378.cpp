#include <bits/stdc++.h>
using namespace std;

int main(){
    int tam = 0, MAXCAP = 0, saida = 0, entrada = 0;
    int sumtotal = 0, merda = 0;


    cin >> tam >> MAXCAP;

    for (int i = 0; i < tam; i++)
    {
        cin >> saida >> entrada;
        sumtotal += (entrada - saida);
        if(sumtotal > MAXCAP){
            merda++;
        }
    }
    
    if(merda > 0){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}