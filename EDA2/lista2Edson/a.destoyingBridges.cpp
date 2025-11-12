#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k){
    int out = n - 1;
    if(k >= out)
        cout << 1 << "\n";
    else
        cout << n << "\n";
}

int main(){
    ios::sync_with_stdio(false);

    int t, n, k;

    cin >> t;

    while(t--){
        cin >> n >> k;

        solve(n, k);
    }

    return 0;
}