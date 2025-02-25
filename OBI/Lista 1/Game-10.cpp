#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, a, cont;

    cin >> n >> d >> a;

    if (a > d)
    {
        cont = (n - a) + d;
    }else
    {
        cont = d - a;
    }
    
    cout << cont << endl;

    return 0;
}