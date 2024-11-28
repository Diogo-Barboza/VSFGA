#include <bits/stdc++.h>
using namespace std;

int main(){
    int tam = 0;
    string entrada;

    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        int seq = 0;
        bool mai = false;
        cin >> entrada;
        transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
        for (int j = 0; j < entrada.size(); j++)
        {
            if (entrada[j] == 'a' || entrada[j] == 'e' || entrada[j] == 'i' || entrada[j] == 'o' || entrada[j] == 'u')
            {
                seq = 0;
            }else{
                seq++;
            }
            if(seq >= 3){
                mai = true;
            }
        }

        entrada[0] = toupper(entrada[0]);

        if (mai)
        {
            cout << entrada << " nao eh facil" << endl;
        }else{
            cout << entrada << " eh facil" << endl;
        }
    }
    

    return 0;
}