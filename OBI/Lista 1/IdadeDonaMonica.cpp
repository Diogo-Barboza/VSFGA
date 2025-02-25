#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, D;

    cin >> A >> B >> C;

    D = (A - B) - C;

    if (B > C && B > D)
    {
        cout << B << endl;
    }else if (C > B && C > D)
    {
        cout << C << endl;
    }else if (D > C && D > B)
    {
        cout << D << endl;
    }

    return 0;
}