#include <bits/stdc++.h>
using namespace std;

int main(){
    int entrada = 0;
    while(cin >> entrada){
        int valor = 0, idas = 0, aux = 0;
        
        if (entrada == -1)
            break;
        
        for (int i = 0; i < entrada; i++)
        {
            cin >> valor;
            aux += valor;

            if (aux % 100 == 0)
            {
                idas++;
            }
        }

        cout << idas << endl;

    }



    return 0;
}