#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, a, n, vt, diarias;

    cin >> d >> a >> n;

    diarias = (31 - n) + 1;

    if (n == 1)
    {
        vt = 31 * d;
    }else if (n >= 2 && n <= 15)
    {
        vt = (d + ((n - 1) * a)) * diarias;
    }else{
        vt = (d + (14 * a)) * diarias;
    }

    cout << vt << endl;
    
    return 0;
}