#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

vector<int> fs(MAX, 0), rs(MAX, 0);

bool solve(int n, int s){
    if(fs[1] == 1){
        if(fs[s] == 1)
            return true;
        for (int i = s+1; i <= n; i++){   
            if(fs[i] == 1 && rs[i] == 1 && rs[s] == 1)
                return true;
        }
    }
    return false;
}

void translate(bool res){
    res ? cout << "YES" << "\n" : cout <<  "NO" <<  "\n";
}

int main(){
    int n, s;
    
    cin >> n >> s;

    for(int i = 1; i <= n; i++){
        cin >> fs[i];
    }
    for(int i = 1; i<= n; i++){
        cin >> rs[i];
    }

    translate(solve(n, s));

    return 0;
}