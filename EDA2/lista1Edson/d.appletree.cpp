#include <bits/stdc++.h>

using namespace std;

const int MAX = {200010};

using ii = pair<int, int>;
vector<int> gr[MAX];

vector<int> filhos[MAX];
vector<int> subarvores(MAX, 0);

void cleaning(){
    for (int i = 0; i < MAX; i++){
        gr[i].clear();
        filhos[i].clear();
    }
}

void dfs(int raiz, int pai){ 
    for(auto v: gr[raiz]){
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

int solve(int x, int y){
    int saida = subarvores[x] * subarvores[y];

    return saida;
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
        cleaning();
        cin >> n;
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