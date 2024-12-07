#include <bits/stdc++.h>
using namespace std;

int main(){
    int tam = 0;
    int aux = 0, aux2 = 0;
    vector<int> time;
    vector<int> litro;
    int sumLitro = 0;
    int sumTempo = 0;

    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cin >> aux >> aux2;
        time.push_back(aux);
        litro.push_back(aux2);
    }
    sumLitro = litro[0];
    for (int i = 1; i < tam; i++)
    {
        sumLitro = (sumLitro - (time[i] - time[i-1]));
        if (sumLitro < 0)
        {
            sumLitro = 0;
        }
        sumLitro = sumLitro + litro[i];
    }
    
    cout << sumLitro << endl;

    return 0;
} 
/* https://atcoder.jp/contests/abc383/tasks/abc383_a */