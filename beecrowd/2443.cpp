#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//Algoritmo do MMC
int mmc(int a, int b){
    return a * (b / gcd(a, b));
}

int main(){
    int a, b, c, d, mdc1, mdc2 = 0;
    cin >> a >> b >> c >> d;

    int frac1, frac2 = 0;
    int cima, baixo = 0;


    baixo = mmc(b, d);   
    cima = ((baixo / b) * a) + ((baixo / d) * c); 

    // cout << "cima: " << cima << endl;
    // cout << "baixo: " << baixo << endl;

    int mdc = gcd(cima, baixo);
    //cout << "MDC: " << mdc << endl;
    
    cima = (cima / mdc);
    baixo = (baixo / mdc);  

    cout << cima << " " << baixo << endl;

    return 0;
}