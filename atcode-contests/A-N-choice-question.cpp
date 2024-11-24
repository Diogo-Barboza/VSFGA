#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1 = 0, tam = 0, n2 = 0;
    int aux = 0;
    vector<int> choices;
    int res = 0;
    
    cin >> tam >> n1 >> n2;
    for (int i = 0; i < tam; i++)
    {
        cin >> aux;
        choices.push_back(aux);
    }

    int sum = 0;
    sum = n1 + n2;

    for (int i = 0; i < tam; i++)
    { 
        if(sum == choices[i])
            res = i + 1;
        
    }
    
    cout << res << endl;

    return 0;
}