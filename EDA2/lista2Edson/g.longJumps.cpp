#include <bits/stdc++.h>
#define MAX 200010

using namespace std;

vector<int> a(MAX);
vector<int> s(MAX);

// [7 3 1 2 3]
// [0 0 0 0 3] j = 4 + 3 = 7; 7<5 ?
// [0 0 0 2 3] j = 3 + 2 = 5; 5<5 ?
// [0 0 3 2 3] j = 2 + 1 = 3; 3<5 -> s[2] = 1 + 2 = 3
// [0 6 3 2 3] j = 1 + 3 = 4 4 < 5 -> s[1] = 3 + 3 = 6 
// [7 6 3 2 3] j = 0 + 7 = 7; 7 < 5;

void solve(int n){
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

    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        solve(n);
    }

    return 0;
}