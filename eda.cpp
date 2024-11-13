#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k = 0;
    string S;
    int cont = 0, morango = 0;


    cin >> n >> k;
    cin >> S;
    
    for (int i = 0; i < n; i++)
    {
        if(S[i] == 'O'){
            cont++;
        }
        else if(S[i] == 'X'){
            if(cont > k && cont % k == 0){
                int div = cont / k;
                morango += div;
                cont = 0;
            }else if(cont >= k)
            {
                morango++;
                cont = 0;
            }
            cont = 0;
        }
    }
    
    cout << morango << endl;

    return 0;
}
