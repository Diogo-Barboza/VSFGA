#include <bits/stdc++.h>

using namespace std;
const int MAX = { 300010};
vector<int> vs[MAX];
int oldAns = 0;

int solve(vector<int> const &olha, int n, int q){
    //Limpo os TODOS os indices 
    for (int i = 0; i < MAX; ++i)
        vs[i].clear();

    //Coloco os índices da ocorrencia de cada
    for (int i = 1; i <= n; i++){
        vs[olha[i]].emplace_back(i);
    }

    int ans = vs[q][0];
    vs[q][0] = 1;
    
    // Pode ser um problema pos é quadratico.
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < vs[i].size(); j++){
            if(vs[i][j] < ans)
                vs[i][j]++;
        }
    }

    // nao ta atualizando os numeros..

    return ans;
    
}

int main(){

    ios::sync_with_stdio(false);

    int n, q, aux;
    cin >> n >> q;

    vector<int> src(n+1);

    for (int i = 0; i < n; i++){
        cin >> src[i+1];        
    }
    for (int j = 0; j < q; j++)
    {
        cin >> aux;
        cout << solve(src, n, aux) << " ";
        oldAns = solve(src, n, aux);
    }

    cout << "\n";

    return 0;
}