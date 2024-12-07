#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 0, b = 0, c = 0;
    int contador = 0;

    cin >> a >> b >> c;
    
    do
    {
        if (a < 2 || b < 3 || c < 5)
        {
            break;
        }
        
        a -= 2;
        b -= 3;
        c -= 5;
        contador++;
    } while (a > 1 && b > 2 && c > 4);
    
    
    cout << contador << endl;

}