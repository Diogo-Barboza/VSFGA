#include <bits/stdc++.h>
#define MAX 200010

using ll = long long;
using namespace std;


void solve(){
    
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> s(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    

    for(int i = n-1; i >= 0; i--){
        s[i] = a[i];
        int j = i + a[i];
        if(j < n){
            s[i] += s[j];
        }
    }

    cout << *max_element(s.begin(), s.end()) << "\n";

}

int main(){
    ios::sync_with_stdio(false);

    int t;

    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}