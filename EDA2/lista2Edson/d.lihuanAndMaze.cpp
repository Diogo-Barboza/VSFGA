#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int x, int y, ll n, ll m){
    //Quina
    if((x == 1 || x == n) && (y == 1 || y == m)) 
        return 2;
    //Borda
    if(x == 1 || y == 1 || x == n || y == m)
        return 3;
    //Qualquer outra posição
    return 4;
}

int main(){
    ios::sync_with_stdio(false);

    int t, x1, y1, x2, y2;
    ll n, m;

    cin >> t;

    while(t--){
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        cout << min(solve(x1,y1,n,m), solve(x2,y2,n,m)) << "\n";
    }

    return 0;
}