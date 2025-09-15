#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int nRoom = 0;
    int num = 0;
    string aux, testa;
    
    vector<string> nomes;

    cin >> nRoom;

    for (int i = 0; i < nRoom; i++)
    {
        cin >> aux;
        nomes.push_back(aux);
    }

    cin >> num >> testa;

    if(num < 1 || num > nRoom){
        cout << "No" << endl;
    }
    else if(nomes[num-1] == testa){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}