#include <bits/stdc++.h>

using namespace std;
const int MAX = {2010};
vector<int> vs[MAX];

void clearVector(vector<int> const &src, int n){
    for(int i = 0; i <= n; i++){
        vs[i].clear();
    }

    for (int i = 1; i <= n; i++){
        if(src[i] == -1)
            vs[i].emplace_back(-1);
        else
            vs[src[i]].emplace_back(i);
    }
}

// 1: -1, 2, 4
// 2: 3
// 3:
// 4:
// 5: -1

int solve(vector<int> const &src, int n){
    int qtdGrupos = 0;
    for (int i = 1; i <= n; i++)
        if(!vs[i].empty())
            qtdGrupos++;
    
    return qtdGrupos;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    vector<int> src(MAX);

    cin >> n;

    
    // lendo todos os employees
    for(int i = 1; i <= n; i++){
        cin >> src[i];
    }

    clearVector(src, n);

    cout << solve(src, n) << "\n";

    return 0;
}