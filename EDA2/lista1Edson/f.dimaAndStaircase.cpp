#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
using ll = long long;


vector<ll> a(MAX, 0);
vector<ll> tam(MAX, 0);

ll maior = a[1];

void solve(ll w, ll h){
    ll aterrisagem = max(a[w], maior);
    maior = aterrisagem + h;
    cout << aterrisagem << "\n";
}


int main(){
    int n, m; 
    ll w, h;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }cin >> m;
    for(ll i = 0; i < m; i++){
        cin >> w >> h;
        solve(w, h);
    }

    return 0;
}