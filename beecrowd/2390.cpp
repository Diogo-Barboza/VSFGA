#include <bits/stdc++.h>
using namespace std;

int main(){
    int tam = 0, sum = 10, aux = 0, dif = 0;
    vector<int> entradas;

    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        cin >> aux;
        entradas.push_back(aux);
    }
    
    for (int i = 1; i < entradas.size(); i++)
    {
        if (entradas[i] > (entradas[i-1]+10))
        {
            dif = 10;
        }else{
            dif = entradas[i] - entradas[i-1];
        }
        sum += dif;
    }
    
    cout << sum << endl;

    return 0;
}