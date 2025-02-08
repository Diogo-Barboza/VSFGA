#include <bits/stdc++.h>
using namespace std;

int main(){
    string entrada;
    while(cin>>entrada){
        if(entrada == "#")
            break;
        
        int tam = entrada.size();

        char aux[tam];
        for (int i = 0; i < tam; i++)
        {
            aux[i] = entrada[i];
        }

        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (aux[j] < aux[i])
                {
                    
                }
                
            }
            
        }
        
        

        cout << entrada << endl;
    }   

    return 0;
}