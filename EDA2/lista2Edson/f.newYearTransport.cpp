#include <bits/stdc++.h>
#define MAX 30010
using namespace std;

// vector<int> a(MAX, 0);
int a[MAX];

bool solve(int n, int t){
    int i = 1;
    while(i < t && i < n){
        i += a[i];
    }
    return i == t;
}

void translate(bool b){
    if(b) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}


int main(){
    ios::sync_with_stdio(false);

    int n, t;

    cin >> n >> t;
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }

    translate((solve(n, t)));

    return 0;
}