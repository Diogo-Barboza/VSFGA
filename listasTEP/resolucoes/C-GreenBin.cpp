#include <bits/stdc++.h>
using namespace std;

int main(){
    int tam = 0;
    string entrada;
    unordered_map<string, int> ordenadas;
    long long cont = 0;

    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        cin >> entrada;
        sort(entrada.begin(), entrada.end());
        ordenadas[entrada]++;
    }
    
    for (auto &i : ordenadas)
    {
        int second = i.second;
        cont += 1LL * second * (second - 1) / 2;
    }
    
    cout << cont << endl;

    return 0;
}