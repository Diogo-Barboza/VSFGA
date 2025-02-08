#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    vector<char> aux;
    int cont = 0;

    cin >> a >> b;

    for (int i = a.size(); i >= 0; i--)
    {
        aux.push_back(a[i]);
    }
    
    for (int i = 0; i < (aux.size() - 1); i++) //GAMBIARRA
    {   
        if (b[i] == aux[i+1]) //GAMBIARRA
        {
            cont++;
        }
    }
    
    if (cont == a.size())
    {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}


/* VERSAO SEM GAMBIARRA - MELHOR
int main() {
    string a, b;
    cin >> a >> b;

    // Verifica se a reversa de 'a' é igual a 'b'
    string reversed_a = a;
    reverse(reversed_a.begin(), reversed_a.end());

    if (reversed_a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
*/