#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

vector<int> p(MAX, 0);
vector<int> adj[MAX];
bitset<MAX> visitado;

void dfs(int u){
    if(visitado[u])
        return;

    visitado[u] = true;

    for(auto v : adj[u])
        dfs(v);
}

int componentesConectados(int n){
    visitado.reset();

    int cont = 0;

    for(int u = 1; u <= n; u++){
        if(not visitado[u]){
            cont++;
            dfs(u);
        }
    }
    return cont;
}

int main(){
    ios::sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;

    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
            adj[i].emplace_back(p[i]);
            // 3 5 6 1 2 4
        }
        cin >> s;
        // done readings

        cout << componentesConectados(n) << "\n";
    }

    return 0;
}

// 1: 3
// 2: 5
// 3: 6
// 4: 1 
// 5: 2
// 6: 4
// 010000
// 4 5 1 6 2 3 
// 4 1 4 4 1 4 