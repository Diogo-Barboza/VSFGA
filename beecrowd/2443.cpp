#include <bits/stdc++.h>
using namespace std;

int gcd(int num1, int num2){
    if(num1%num2==0)
        return num2;
    else
        return gcd(num2, num1%num2);
}

int main(){
    cout << gcd(55, 21) << endl;
    int a, b, c, d, mdc1, mdc2 = 0;
    cin >> a >> b >> c >> d;
    int frac1, frac2 = 0;
    int cima, baixo = 0;

    if (b % d == 0 || d % b == 0) // 3 3 ou 3 6
    {
        if (b == d || b > d)
        {
            baixo = b;
        }else
        {
            baixo = d;
        }
        
    }else{
        baixo = b * d;
    }
    
    cima = ((baixo / b) * a) + ((baixo / d) * c);

    
    if(gcd(cima, baixo) > 1){
        cima = (cima / gcd(cima, baixo));
        baixo = (baixo / gcd(cima, baixo));  
    }

    cout << cima << baixo << endl;

    return 0;
}