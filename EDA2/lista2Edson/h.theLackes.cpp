#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

int n, m;

int matriz[MAX][MAX];
bool vis[MAX][MAX];

int dfs(int i, int j){
    vis[i][j] = true;
    int soma = matriz[i][j];

    // Esquerda
    if(i != 0 && matriz[i-1][j] != 0 && vis[i-1][j] != true) 
        soma += dfs(i-1, j);
    // Cima
    if(j != 0 && matriz[i][j-1] != 0 && vis[i][j-1] != true)
        soma += dfs(i, j-1);
    //Direita
    if(i != n-1 && matriz[i+1][j] != 0 && vis[i+1][j]!= true)
        soma += dfs(i+1, j);
    //Baixo
    if(j != m-1 && matriz[i][j+1] != 0 && vis[i][j+1] != true)
        soma += dfs(i, j+1);
    
    return soma;
}

void solve(){
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && matriz[i][j] != 0)
                res = max(dfs(i, j), res);
        } 
    }

    cout << res << "\n";
}

int main(){

    ios::sync_with_stdio(false);

    int t;

    cin >> t;

    while(t--){
        cin >> n >> m;

        //input matrix
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                vis[i][j] = false;
                cin >> matriz[i][j];
            }
        }

        solve();
    }

    return 0;
}

