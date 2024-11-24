#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 0, y = 0;
    int conta = 0, contb = 0;
    string aux;

    cin >> x >> y;

    vector<string> a;
    vector<string> b;

    for (int i = 0; i < x; i++)
    {
        cin >> aux;
        a.push_back(aux);
    }
    for (int i = 0; i < x; i++)
    {
        cin >> aux;
        b.push_back(aux);
    }
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if(a[i][j] == '#')
                conta++;
            if(b[i][j] == '#')
                contb++;
        }
    }
    
    
    if(conta == contb){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}