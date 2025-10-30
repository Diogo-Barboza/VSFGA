#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAX = {200010};

vector<int> gr[MAX];
vector<int> filhos[MAX];

vector<ll> subarvores(MAX, 0);

void cleanOnce(){
    for (int i = 0; i < MAX; i++){
        gr[i].clear();
        filhos[i].clear();
    }
}

void cleaning(int N){
    for (int i = 0; i < N; i++){
        gr[i].clear();
        filhos[i].clear();
        subarvores[i] = 0;
    }
}

void dfs(int raiz, int pai){
    for(auto v : gr[raiz]){
        if(v != pai){
            filhos[raiz].emplace_back(v);
            dfs(v, raiz);
        }
    }
}

int contagem(int raiz){
    if(filhos[raiz].empty()){
        subarvores[raiz] = 1;
        return 1;
    }

    int cont = 0;

    for(auto v : filhos[raiz]){
        cont += contagem(v);
    }

    subarvores[raiz] = cont;

    return cont;
}

ll solve(int x, int y){
    return subarvores[x] * subarvores[y];
}


int main(){

    ios::sync_with_stdio(false);

    int t; 
    int n;
    int u, v;
    int q;
    int x , y;
    
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cleaning(n+5);
        for(int j = 1; j < n; j++){
            cin >> u >> v;
            gr[u].emplace_back(v);
            gr[v].emplace_back(u);
        }

        dfs(1,0);
        contagem(1);

        cin >> q;
        for(int k = 1; k <= q; k++){
            cin >> x >> y;
            cout << solve(x, y) << "\n";
        }
    }
}