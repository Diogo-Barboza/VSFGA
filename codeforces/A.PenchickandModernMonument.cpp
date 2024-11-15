#include <bits/stdc++.h>
using namespace std;

int main() {
    int tam = 0;
    int tamvec = 0;
    int entorder = 0;
    vector<int> order;
    int cont = 0;
    int contagem = 2;

    cin >> tam;


    for (int i = 0; i < tam; i++)
    {
        cin >> tamvec;

        for (int j = 0; j < tamvec; j++)
        {
            cin >> entorder;
            order.push_back(entorder);
        }

        for (int k = 0; k < tamvec; k++) //[5,4,3,2,1]
        {
            if(order[k] < order[k + 1]){
                if(cont == 2){
                    contagem += 1;
                    cont = 0;
                }
                swap(order[k], contagem);
                cont++;
            }

            cout << order[i] << ',';
        }
        
    }
    
    return 0;
}