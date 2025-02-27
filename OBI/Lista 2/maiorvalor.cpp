#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, s, soma = 0;

    cin >> n >> m >> s;

    for (int i = m; i >= n; i--)
    {
        while (i > 0)
        {
            soma += i % 10;
            // i = i / 10;
        }
        if(soma == s){
            cout << soma << endl;
            break;
        }
        
    }

    
    return 0;
}