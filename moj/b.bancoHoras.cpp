#include <bits/stdc++.h>

using namespace std;

void solve(int d, int soma){
    int meta = d * 8;

    if(soma < meta)
        cout << "Horas a serem pagas: " << meta - soma << " hora(s)" << "\n";
    else if(soma > meta)
        cout << "Banco de horas: " << soma - meta << " hora(s)" << "\n";
    else
        cout << "A jornada de trabalho foi cumprida" << "\n";
}

int main(){
    int d, soma = 0, aux = 0;

    cin >> d;

    for (int i = 0; i < d; i++){
        cin >> aux;
        soma += aux;
    }

    solve(d, soma);

    return 0;
}