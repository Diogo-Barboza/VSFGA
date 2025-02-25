#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, a, f, p, cont = 0;
    
    cin >> v >> a >> f >> p;

    int lista[3] = {a, f, p};
    int len = sizeof(lista)/sizeof(lista[0]);
    
    sort(lista, lista + len);

    for (int i = 0; i <= 2; i++)
    {
        if (v - lista[i] >= 0)
        {
            v -= lista[i];
            cont++;
        }
        
    }
    
    cout << cont << endl;

    return 0;
}