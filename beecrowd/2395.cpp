#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y, z = 0;
    int qtdlarg, qtdcomp, qtdalt = 0;

    cin >> a >> b >> c >> x >> y >> z;

    qtdcomp = y / b;
    qtdlarg = x / a;
    qtdalt  = z / c;

    cout << (qtdalt * qtdcomp * qtdlarg) << endl;

    return 0;
}