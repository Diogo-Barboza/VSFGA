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

/*
3
50 50 50
5
50 100 100 100 100
9
25 50 75 100 25 50 75 100 25
5
35 45 20 22 33
3
100 100 100
-1
*/