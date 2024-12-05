#include <bits/stdc++.h>
using namespace std;

int main(){
    int tam=0, I=0, S = 0, aux=0, contador = 0;
    vector<int> v;

    cin >> tam >> I >> S;
    for (int i = 0; i < tam; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }

    for (int i = 0; i < tam; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if ((v[i] + v[j] >= I) && (v[i] + v[j] <= S))
            {
                contador++;
            }   
        }
    }
    
    cout << contador << endl;

    return 0;
}