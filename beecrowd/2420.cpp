#include <bits/stdc++.h>
using namespace std;

int main() {
    int tam = 0, aux = 0;
    vector<int> sum;

    int soma = 0, pivo = 0, achou = 0;

    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        cin >> aux;
        soma += aux;
        sum.push_back(aux);
    }

    pivo = soma / 2;
    soma = 0;

    for (int i = 0; i < sum.size(); i++)
    {
        soma += sum[i];
        if(soma == pivo){
            achou = (i + 1);
            break;
        }
    }
    
    cout << achou << endl;

    return 0;
}