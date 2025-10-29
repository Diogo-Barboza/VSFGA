#include <bits/stdc++.h>

using namespace std;
const int MAX = {2010};
vector<int> vs[MAX];
vector<int> chefes(MAX);
int groups = 0;

void dfs(int funcionario, int nivelAtual){
    groups = max(groups, nivelAtual);

    for(auto i : vs[funcionario])
        dfs(i, nivelAtual+1);
}

void clearVector(vector<int> const &src, int n){
    for(int i = 0; i <= n; i++){
        vs[i].clear();
    }

    for (int i = 1; i <= n; i++){
        if(src[i] != -1)
            vs[src[i]].emplace_back(i);
        else 
            chefes.emplace_back(i);
    }
}

void solve(){
    for(auto v : chefes)
        dfs(v, 1);
}


int main(){
    ios::sync_with_stdio(false);
    int n;
    vector<int> src(MAX);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> src[i];
    }

    clearVector(src, n);

    solve();

    cout << groups << "\n";

    return 0;
}