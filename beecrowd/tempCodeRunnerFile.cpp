#include <bits/stdc++.h>
using namespace std;

int gcd(int num1, int num2){
    if(num1%num2==0)
        return num2;
    else
        return gcd(num2, num1%num2);
}

int mmc(int num1, int num2) {

    int mmc, aux, i;

    for (i = 2; i <= num2; i++) {
        aux = num1 * i;
        if ((aux % num2) == 0) {
            mmc = aux;
            i = num2 + 1;
        }
    }
    return mmc;
}

int main(){
    int a, b, c, d, mdc1, mdc2 = 0;
    cin >> a >> b >> c >> d;
    int frac1, frac2 = 0;
    int cima, baixo = 0;


    baixo = mmc(b, d);    
    cima = ((baixo / b) * a) + ((baixo / d) * c); // a / b + c / d = cima / baixo

    
    cima = (cima / gcd(cima, baixo));
    baixo = (baixo / gcd(cima, baixo));  
    

    cout << cima << " " << baixo << endl;

    return 0;
}