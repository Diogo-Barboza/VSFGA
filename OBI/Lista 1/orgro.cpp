#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, d, saida;

    cin >> e >> d;

    if (e > d)  
    {
        saida = e+d;
    }else{
        saida = (2 * (e-d));
        if(saida<0) saida *= -1;
    }
    
    cout << saida << endl;
    return 0;
}