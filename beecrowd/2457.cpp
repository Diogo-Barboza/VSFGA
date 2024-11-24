#include <bits/stdc++.h>
using namespace std;

int main(){
    char pri;
    string ent;
    float palavra = 0, cont = 0, contREAL = 0;

    cin >> pri;
    cin.ignore(); // limpa o buffer
    getline(cin, ent);

    for (int i = 0; i < ent.size(); i++)
    {   
        if(ent[i] == pri){
            cont += 1;
        }
        if(ent[i] == ' ' || i == (ent.size() - 1)){
            palavra += 1;
            if (cont >= 1)
            {
                contREAL++;
            }
            cont = 0;
        }
        
    }

    float porcem = 0;
    porcem = (100 * contREAL) / palavra;

    cout << fixed << setprecision(1);
    cout << porcem << endl;
    // cout << contREAL << endl << palavra << endl;

    return 0;
}