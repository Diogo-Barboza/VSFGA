#include <bits/stdc++.h>
using namespace std;

int main(){
    int ia, ib, fa, fb;

    cin >> ia >> ib >> fa >> fb;

    if (ia == fa && ib == fb)
    {
        cout << 0 << endl;
    }else if (ia == fa && ib != fb)
    {
        cout << 2 << endl;
    }else{
        cout << 1 << endl;
    }

    return 0;
}